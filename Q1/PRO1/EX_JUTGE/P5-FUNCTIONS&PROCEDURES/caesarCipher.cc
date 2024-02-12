#include <iostream>
using namespace std;

/**
 * PRE: c is a lowcase char
 * POST: returns the cipher char
*/
char encoded(char c, int k);

int main() {
   int k;
   char c;
   while (cin >> k){
      while (cin >> c and c != '.') cout << encoded(c,k);
      cout << endl;
   }
}

char encoded(char c, int k) {
   const int ALFA_INTERVAL = 'z' - 'a';
   const int TO_CAPS = 'a' - 'A';
   int encoded_char = c + k%(ALFA_INTERVAL+1);
   if ('a' <= c and c <= 'z') {
      if ('z' < encoded_char) return char(encoded_char - (ALFA_INTERVAL + TO_CAPS + 1));
      else return char(encoded_char - TO_CAPS);
   }
   if (c == '_') return ' ';
   else return c;
}