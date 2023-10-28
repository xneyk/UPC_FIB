#include <iostream>
using namespace std;

int main() {
   char letter;
   int c = 0;
   int d = 0;
   bool a_found = false;
   int valid_d = 0; 
   /**
    * a_found actua com a validador de 'c' si desde que s'ha trobat 'a' fins
    * fins que es troba la 'c' no hi ha cap 'b' aquesta 'a' es valida per comptar la 'c'.
    * 
    * Es parteix de la hipostesi que a mesura que es troben 'd' son valides fins 
    * que no es trobi una 'b' abans que una 'a'. 
   */
   while (cin >> letter) {
      if(not (letter == 'b')) {
         if (letter == 'a') {
            a_found = true;
            if (valid_d > 0) {
               d += valid_d;
               valid_d = 0;
            }
         } else {
            if (letter == 'c' and a_found) ++c;
            else if (letter == 'd') ++valid_d;
         }
      } else {
         a_found = false; // aquesta a deixa de ser valida per validar 'c'.
         valid_d = 0; // S'invaliden totes les d acumulades.
      }
   }
   cout << c << ' ' << d << endl;
}