#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

void usage() {
   char msg[64];
   sprintf(msg, "usage:\t./p2 <n1 t1> [<n2 t2> ..]\n");
   write(2, msg, strlen(msg));
   exit(1);
}

void error_and_exit(char *err_msg) {
   perror(err_msg);
   exit(1);
}

// int main(int argc, char **argv)