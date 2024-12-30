#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
   int fd = creat("./salida.txt", 0600);
   // the same that open("./salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600);
   // 0600 --> rw- --- ---
   
   char buffer[16];
   sprintf(buffer, "ABCD");
   write(fd, buffer, strlen(buffer));
   
   close(fd);
}