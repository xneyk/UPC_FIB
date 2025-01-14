#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

void usage() {
   char buffer[64];
   // No proporcionar almenos un nombre de fichero no es que sea un error pero no sirve de mucho...
   // de aqui que se inluya en el usage minimo uno obligatiorio.
   sprintf(buffer, "usage: ./multiparser file_name1 [file_name2 ...]\n");
   write(2, buffer, strlen(buffer));
   exit(1);
}

void error_and_exit(char *msg) {
   perror(msg);
   exit(1);
}

void wake_up(int s) {
   // NOP, just for doing nothing on alarm wake up
}

int main(int argc, char **argv) {
   if (argc < 2) usage();

   sigset_t mask;
   struct sigaction sa;
   sigfillset(&mask);
   sigprocmask(SIG_BLOCK, &mask, NULL); // Block all signals

   sigfillset(&sa.sa_mask);
   sa.sa_handler = wake_up;
   sigaction(SIGALRM, &sa, NULL); // program ALRM for doing nothing and not die.

   int fd_filein;
   // create namedpipe for block and unblock child process
   if (mknod("namedpipe", S_IFIFO | 0640, 0) < 0 && errno != EEXIST) error_and_exit("Error while creating namedpipe");
   
   char msg[256];
   for (int i = 1; i < argc; ++i) { // for each given file
      // create pipe
      int fd_pipe[2];
      if (pipe(fd_pipe) < 0) error_and_exit("Error while creating unnamed pipe");
      
      int fork_res = fork();
      if (fork_res > 0) { // father code
         if (close(fd_pipe[0]) < 0) error_and_exit("Error on close pipe read endpoint"); // if father didn't close read endpoint from pipe ==> close it.
         
         fd_filein = open(argv[i], O_RDONLY);
         if (fd_filein < 0) error_and_exit("Error while openning file");

         alarm(2);
         sigdelset(&mask, SIGALRM);
         sigsuspend(&mask);
         
         // this will unblock child process
         sprintf(msg, "Proceso principal despertando proceso child %d\n", i);
         write(2, msg, strlen(msg));

         int blocking_pipe = open("namedpipe", O_WRONLY);
         if (blocking_pipe < 0) error_and_exit("Error on openning namedpipe");
         if (close(blocking_pipe) < 0) error_and_exit("Error on close namedpipe");

         char c;
         int ret;
         while ((ret = read(fd_filein, &c, sizeof(char))) > 0) {
            if (write(fd_pipe[1], &c, ret) < 0) error_and_exit("Error while reading from file"); 
         }

         if (close(fd_pipe[1]) < 0) error_and_exit("Error on close pipe write endpoint");
         if (close(fd_filein) < 0) error_and_exit("Error on close file");

         int stat;
         waitpid(fork_res, &stat, 0);
         if (WIFEXITED(stat)) {
            sprintf(msg, "Proceso child %d ha finalizado voluntariamente\n", i);
            write(2, msg, strlen(msg));
         }

      } else if (fork_res == 0) { // child code
         // Block child process
         int blocking_pipe = open("namedpipe", O_RDONLY); // this open will block the process till pather open the pipe.
         sprintf(msg, "Proceso child %d despertado\n", i);
         write(2, msg, strlen(msg));

         if (blocking_pipe < 0) error_and_exit("Error on openning namedpipe");
         if (close(blocking_pipe) < 0) error_and_exit("Error on close namedpipe");
         
         
         if (dup2(fd_pipe[0], 0) < 0) error_and_exit("Error on dup2 to channel 0");
         
         if (close(fd_pipe[0]) < 0) error_and_exit("Error on close pipe read endpoint");
         if (close(fd_pipe[1]) < 0) error_and_exit("Error on close pipe write endpoint");

         char filename[64];
         sprintf(filename, "%s.out", argv[i]);
         // file need to be open at channel 4
         int fd_fileout;
         if ((fd_fileout = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0640)) < 0) error_and_exit("Error while openning file");
         if (dup2(fd_fileout, 4) < 0) error_and_exit("Error on dup2 to channel 4");
         if (close(fd_fileout) < 0) error_and_exit("Error on close fileout channel");
         
         execlp("./parser", "./parser", (char *) NULL);
         
         error_and_exit("Error on execlp");
      } else {
         error_and_exit("Error on fork");
      }
   }

   sprintf(msg, "Final del proceso principal\n");
   write(2, msg, strlen(msg));
}