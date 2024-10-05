#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * Muestra un mensaje descriptivo sobre el uso del programa y aborta la ejecucion.
*/
void usage(char *str) {
	char buffer[512];
	sprintf(buffer, "Usage: %s \"arg1\"\nEste programa escribe por su salida el numero de palabras que tiene la frase recbida.\n(Trata unicamente el primer parametro, debe estar contenido entre \" \")\n", str);
	write(1, buffer, strlen(buffer));

	exit(0); // abort without error.
}

int main(int argc, char **argv) {
   if (argc < 2) usage(argv[0]);

   int words = 0, new_word = 1;
   int size = strlen(argv[1]);
   char *s = argv[1];
   for (int i = 0; i < size; ++i) {
      if (s[i] == ' ' || s[i] == '.' || s[i] == ',' || s[i] == '\n') {
         new_word = 1;
      } else {
         if (new_word) ++words;
         new_word = 0;
      }
   }

   char buffer[32];
   sprintf(buffer, "%d palabras\n", words);
   write(1, buffer, strlen(buffer));
   return 0;
}