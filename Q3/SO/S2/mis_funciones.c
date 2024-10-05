#include <stdlib.h>
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

unsigned int char2int(char c) {
   return c - '0';
}

int mi_atoi(char *s) {
   int n = 0, is_negative = 0;
   int size = strlen(s);
   for (int i = 0; i < size; ++i) {
      if (s[i] == '-') is_negative = 1;
      else {
         n *= 10;
         n += char2int(s[i]);
      }
   }
   
   if (is_negative) n *= -1;
   return n;
}
