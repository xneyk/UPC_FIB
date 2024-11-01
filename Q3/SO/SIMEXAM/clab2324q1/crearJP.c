#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/errno.h>
#include <signal.h>

void error_and_exit(char *err_msg, int err_code) {
   perror(err_msg);
   exit(err_code);
}

void usage() {
   char buffer[128];
   sprintf(buffer, "usage: crearJP <nchilds1> <nchilds2>, 1 <= nchilds1 <= 10, 1 <= nchilds2 <= 5\n");
   write(1, buffer, strlen(buffer));
   exit(1);
}

void handleSignal(int s) {
   char buffer[256];
   switch (s) {
      case SIGUSR1:
         sprintf(buffer, "Soy el proceso %d (hijo de %d)\n", getpid(), getppid());
         write(1, buffer, strlen(buffer));
   }
}

int main(int argc, char **argv) {
   if (argc != 3) usage();
   int nchilds1 = strtol(argv[1], (char **)NULL, 10);
   int nchilds2 = strtol(argv[2], (char **)NULL, 10);
   if (!((1 <= nchilds1 && nchilds1 <= 10) && (1 <= nchilds2 && nchilds2 <= 5))) usage();

   // Block Signals to prevent losing it.
   sigset_t mask;
   sigemptyset(&mask);
   sigaddset(&mask, SIGALRM);
   sigaddset(&mask ,SIGUSR1);
   sigaddset(&mask, SIGUSR2);
   sigprocmask(SIG_BLOCK, &mask, NULL);

   struct sigaction sa;
   sa.sa_flags = 0; // restore default handle after first reception.
   sigfillset(&sa.sa_mask); // block all signals during treatment
   sa.sa_handler = &handleSignal;
   sigaction(SIGALRM, &sa, NULL); // same treatment for both levels

   int pid[nchilds1];
   for (int i = 0; i < nchilds1; ++i) {
      pid[i] = fork(); // creating n first level childs

      if (pid[i] < 0) error_and_exit("failed to fork", 1);
      
      else if (pid[i] == 0) { // first level childs code
         // mask prepare to wait for SIGUSR1 SIGUSR2 at both levels
         sigfillset(&mask);
         sigdelset(&mask, SIGUSR1);
         sigdelset(&mask, SIGUSR2);

         sa.sa_flags = 0; // restore default handle after first reception.
         sigfillset(&sa.sa_mask); // block all signals during treatment
         sa.sa_handler = &handleSignal;
         sigaction(SIGUSR1, &sa, NULL); // same treatment for both levels

         int chld_pid[nchilds2];
         for (int j = 0; j < nchilds2; ++j) {
            chld_pid[j] = fork();
            if (chld_pid < 0) error_and_exit("failed to fork in second level", 1);
            else if (chld_pid[j] == 0) { // second level childs code
               sigsuspend(&mask);
               exit(0);
            }
         }

         sigsuspend(&mask);
         for (int j = 0; j < nchilds2; ++j) {
            kill(chld_pid[j], SIGUSR1);
         }
         while (waitpid(-1, NULL, 0) > 0);
         exit(0);
      }
   }

   char buffer[128];
   sprintf(buffer, "Soy el proceso %d (raiz de la jerarquia)\n", getpid());
   write(1, buffer, strlen(buffer));

   alarm(60);
   sigfillset(&mask);
   sigdelset(&mask, SIGALRM);
   sigsuspend(&mask);
   for (int i = 0; i < nchilds1; ++i) {
      kill(pid[i], SIGUSR1);
   }

   while (waitpid(-1, NULL, 0) > 0);
}