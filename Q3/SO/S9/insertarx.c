#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void usage() {
   char buffer[256];
   sprintf(buffer, "usage: ./insertarx file_name\n");
   write(1, buffer, strlen(buffer));
   exit(1);
}

int main(int argc, char **argv) {
   if (argc != 2) usage();

   int fd = open(argv[1], O_RDWR);
   
   char last_char;
   char to_insert = 'X';
   // move r/w pointer to (end - 1) position
   lseek(fd, -1, SEEK_END);
   read(fd, &last_char, 1);
   // move r/w pointer to (end - 1) position another time, cause it has been moved by read op.
   lseek(fd, -1, SEEK_END);
   write(fd, &to_insert, 1);
   write(fd, &last_char, 1);
   close(fd);
}