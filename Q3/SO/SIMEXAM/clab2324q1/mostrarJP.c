#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/errno.h>
#include <signal.h>

const int pid_max = 99998;

void error_and_exit(char *err_msg, int err_code) {
   perror(err_msg);
   exit(err_code);
}

void usage() {
   char buffer[128];
   sprintf(buffer, "usage: program need to recive one argument\n./mostrarJP <PID>\n");
   write(1, buffer, strlen(buffer));
   exit(1);
}

int main(int argc, char **argv) {
   if (argc != 2) usage();
   int pid = strtol(argv[1], (char **)NULL, 10); // process pid
   assert(0 < pid && pid < pid_max); // check is a valid pid.
   kill(pid, 0);
   assert(errno != ESRCH);

   if (fork() > 0) {
      execlp("pstree", "pstree", "-p", argv[1], (char *)0);
      error_and_exit("failed to change execution to pstree", 1);
   } else {
      waitpid(-1, NULL, 0); // wait for him unique child.
   }
}