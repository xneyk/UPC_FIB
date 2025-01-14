#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void usage() {
   char buffer[64];
   sprintf(buffer, "usage: ./parser [file_name]\n");
   write(2, buffer, strlen(buffer));
   exit(1);
}

void error_and_exit(char *msg) {
   perror(msg);
   exit(1);
}

int main(int argc, char **argv) {
   if (argc > 2) usage();
   
   int fd_in = 0;

   if (argc == 2) { // program has recived a file_name to open
      fd_in = open(argv[1], O_RDONLY | O_CREAT, 0644);
      if (fd_in < 0) perror("Error while opening the indicated file");
   }

   int *position = sbrk(0); // vector to store the '\n' positions.
   // need to keep vector's first position.
   int vector_size = 0;

   int n;
   int read_bytes = 0;
   char c;
   while ((n = read(fd_in, &c, sizeof(char)) > 0)) {
      if (c == '\n') {
         int *new_elem = sbrk(sizeof(int));
         if (new_elem < 0) perror("Error while heap reservation");
         *new_elem = read_bytes;
         ++vector_size;
      }
      ++read_bytes;
   }
   if (n < 0) perror("Error while reading from the indicated file");

   write(4, position, vector_size*sizeof(int));
   
   char buffer[256];
   sprintf(buffer, "El texto tiene %d saltos de linea y se han utilizado %d Bytes del heap\n", vector_size, vector_size*sizeof(int));
   write(2, buffer, strlen(buffer));
}