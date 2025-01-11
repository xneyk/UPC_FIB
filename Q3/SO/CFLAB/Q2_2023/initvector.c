#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void error_and_exit(char *msg) {
   perror(msg);
   exit(1);
}

void usage() {
   char buffer[256];
   sprintf(buffer, "Error: uso: ./initvector <número_par> [nombre_fichero]\n");
   write(2, buffer, strlen(buffer));
   exit(1);
}

int main(int argc, char **argv) {
   if (argc < 2 || argc > 3) usage();
   int vector_size = atoi(argv[1]);
   if (vector_size%2 != 0) usage();

   int *vector = sbrk(vector_size*sizeof(int)); // reserve memory for vector at heap.
   if (vector < 0) error_and_exit("Error while sbrk get memory syscall");

   for (int i = 0; i < vector_size; ++i) {
      vector[i] = i; // set vector values.
   }

   int destination = 1; // stdout default destination

   if (argc == 3) { // argv[2] = file_name where data need to be placed.
      int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0640); // permission rw- r-- --- if file doesn't exist.
      if (fd < 0) error_and_exit("Error while open syscall");

      destination = fd; // change destination to fd (user indicated file)
   }

   int wr_ret = write(destination, &vector_size, sizeof(int)); // write vector size
   if (wr_ret < 0) error_and_exit("Error while write vector_size syscall");
   wr_ret = write(destination, vector, sizeof(int)*vector_size); // write vector content.
   if (wr_ret < 0) error_and_exit("Error while write vector syscall");

   int *sbrk_ret = sbrk(-vector_size*sizeof(int)); // free vector memory 
   if (sbrk_ret < 0) if (vector < 0) error_and_exit("Error while sbrk free memory syscall");

   exit(0);
}