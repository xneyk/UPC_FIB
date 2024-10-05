#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

const int MAX_SIZE = 8;

int esNumero(char *str) {
   int size = strlen(str);
   if (str == NULL || size > MAX_SIZE) return 0; // comprovem els requisits del vector
   else {
      for (int i = 0; i < size; ++i) {
         if (str[i] < '0' || '9' < str[i]) { // si en algun punt no es un numero
            if (!(i == 0 && str[i] == '-')) return 0; // y no es tracta del cas escepcional del signe negatiu davant.
         }
      }
      return 1;
   }
}

int main(int argc, char *argv[]) {
   char buffer[128];
   for (int i = 1; i < argc; ++i) {
      if (esNumero(argv[i])) sprintf(buffer, "%s SI es un numero\n", argv[i]);
      else sprintf(buffer, "%s NO es un numero\n", argv[i]);
      
      write(1, buffer, strlen(buffer));
   }
}