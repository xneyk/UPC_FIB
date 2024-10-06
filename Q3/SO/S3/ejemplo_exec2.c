#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
   char buffer[80];

   sprintf(buffer, "Soy el proceso: %d\n", getpid());
   write(1, buffer, strlen(buffer));

   execlp("./ejemplo_fork1.x", "ejemplo_fork1", (char *)0);

   strcpy(buffer, "Después del exec\n");
   write(1, buffer, strlen(buffer));
}
