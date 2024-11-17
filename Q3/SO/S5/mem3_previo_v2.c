#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define REGION_SIZE 4096

int *p;

void sigsegv_handler(int s) {
   perror("Se ha prducido un violacion de segmento");
   exit(1);
}

int main(int argc, char *argv[]) {
   struct sigaction sa;
   sa.sa_flags = SA_RESTART;
   sigemptyset(&sa.sa_mask);
   sa.sa_handler = &sigsegv_handler;
   sigaction(SIGSEGV, &sa, NULL); // capture signal

   char buff[256];

   sprintf(buff, "Addresses:\n");
   write(1, buff, strlen(buff));
   sprintf(buff, "\tp: %p\n", &p);
   write(1, buff, strlen(buff));

   *p = 5;

   sprintf(buff, "\tp Address: %p, p value: %p, *p: %d\n", &p, p, *p);
   write(1, buff, strlen(buff));

   exit(0);
}
