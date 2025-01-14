#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void usage() {
   char buffer[64];
   sprintf(buffer, "usage: ./modifier file_name n1 [n2 n3 n4 ...]\n");
   write(2, buffer, strlen(buffer));
   exit(1);
}

void error_and_exit(char *msg) {
   perror(msg);
   exit(1);
}

int main(int argc, char **argv) {
   if (argc < 3) usage();

   int fd_text = open(argv[1], O_WRONLY);
   if (fd_text < 0) error_and_exit("Error while openning file");
   
   char file_name[32];
   sprintf(file_name, "%s.out", argv[1]);
   int fd_textout = open(file_name, O_RDONLY);
   if (fd_textout < 0) error_and_exit("Error while openning file.out");

   int size = lseek(fd_textout, 0, SEEK_END); // how many bytes file.out have
   for (int i = atoi(argv[2]); i < argc; ++i) { // for each possible jump gived
      int jump = atoi(argv[i]);
      if (jump*sizeof(int) > size) {
         char buffer[128];
         sprintf(buffer, "El salto de linea %d no esta en el rango de este fichero\n", jump);
         write(1, buffer, strlen(buffer));
      } else { // these jump exists
         // move pointer for reading the given jump
         if (lseek(fd_textout, (jump - 1)*sizeof(int), SEEK_SET) < 0) error_and_exit("Error while moving text.out's r/w pointer");
         int text_offset;
         if (read(fd_textout, &text_offset, sizeof(int)) < 0) error_and_exit("Error while reading from file.out");
         if (lseek(fd_text, text_offset, SEEK_SET) < 0) error_and_exit("Error while moving text's r/w pointer");
         char replacement = '-';
         if (write(fd_text, &replacement, sizeof(char)) < 0) error_and_exit("Error while writting on text");
      }
   }
}