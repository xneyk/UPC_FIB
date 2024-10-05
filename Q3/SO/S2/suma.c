#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "mis_funciones.h"

// const int MAX_SIZE = 8;

// int esNumero(char *str) {
//    int size = strlen(str);
//    if (str == NULL || size > MAX_SIZE) return 0; // comprovem els requisits del vector
//    else {
//       for (int i = 0; i < size; ++i) {
//          if (str[i] < '0' || '9' < str[i]) { // si en algun punt no es un numero
//             if (!(i == 0 && str[i] == '-')) return 0; // y no es tracta del cas escepcional del signe negatiu davant.
//          }
//       }
//       return 1;
//    }
// }

// unsigned int char2int(char c) {
//    return c - '0';
// }

// int mi_atoi(char *s) {
//    int n = 0, is_negative = 0;
//    int size = strlen(s);
//    for (int i = 0; i < size; ++i) {
//       if (s[i] == '-') is_negative = 1;
//       else {
//          n *= 10;
//          n += char2int(s[i]);
//       }
//    }
   
//    if (is_negative) n *= -1;
//    return n;
// }

/**
 * Muestra un mensaje descriptivo sobre el uso del programa y aborta la ejecucion.
*/
void usage(char *str) {
	char buffer[512];
	sprintf(buffer, "Usage: %s arg1 arg2 [arg3..argn]\nEste programa escribe por su salida la suma de los argumentos que recibe.\n(Debe recibir al menos dos argumentos).\n", str);
	write(1, buffer, strlen(buffer));

	exit(0); // abort without error.
}

int main(int argc, char *argv[]) {
   if (argc <= 2) usage(argv[0]);

   char buffer[128];
   int acumulated = 0;

   for (int i = 1; i < argc; ++i) {
      if (!esNumero(argv[i])) {
         sprintf(buffer, "Error: el parametro \"%s\" no es un numero\n", argv[i]);
         write(2, buffer, strlen(buffer));
         exit(-1);
      }
      acumulated += mi_atoi(argv[i]);
   }

   sprintf(buffer, "La suma es: %d\n", acumulated);
   write(1, buffer, strlen(buffer));

   return 0;
}