#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

void usage() {
   char msg[64];
   sprintf(msg, "usage:\t./p1 <n> [t]\n");
   write(2, msg, strlen(msg));
   sprintf(msg, "\t./p1-char.exe <n>\n");
   write(2, msg, strlen(msg));
   sprintf(msg, "\t./p1-integer.exe <n>\n");
   write(2, msg, strlen(msg));
   exit(1);
}

void error_and_exit(char *err_msg) {
   perror(err_msg);
   exit(1);
}

void wake_up(int s) {} // just for waking up from sigsuspend without killing the process.

int main(int argc, char **argv) {
   if (argc != 2 && argc != 3) usage();

   int n = atoi(argv[1]);
   int data_size = sizeof(char);
   
   if (argc == 2) {
      if (strcmp("./p1-integer.exe", argv[0])) data_size = sizeof(int);
      // else is ./p1-char.exe ==> default data size is set to char.
   } else { // argc == 3
      if (argv[2][0] == 'i') data_size = sizeof(int);
      // else argv[2] == 'c' ==> default data size is set to char.
   }

   // SIGUSR1 handler (avoid killing the process if recived)
   struct sigaction sa;
   sigemptyset(&sa.sa_mask);
   sa.sa_handler = wake_up;
   if (sigaction(SIGUSR1, &sa, NULL) < 0) error_and_exit("Error on sigaction");

   sigset_t mask;
   sigfillset(&mask);
   sigdelset(&mask, SIGUSR1);
   sigsuspend(&mask); // wait for a SIGUSR1 to continue

   char buffer[128];
   sprintf(buffer, "El proceso %d comienza\n", getpid());
   write(1, buffer, strlen(buffer));
   
   for (int i = 0; i < n; ++i) {
      if (write(10, &i, data_size) < 0) error_and_exit("Error while writting at channel 10");
   }

   sprintf(buffer, "El proceso %d ha terminado\n", getpid());
   write(1, buffer, strlen(buffer));
}