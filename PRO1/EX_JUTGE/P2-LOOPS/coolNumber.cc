#include <iostream>
using namespace std;

int main() {
   int n;
   int r = 0;
   // On n es el nombre entrat i r el resultat.
   cin >> n;

   /**
    * Amb intencio d'estalviar memoria, fem un cout d'n abans de modificar-la,
    * d'aquesta manera, no cal fer us d'una variable extra per a copiar el valor
    * inicial d'n.
   */

  cout << n;

   while (n > 0) {
      r += n % 10;
      n /= 100;
   }

   if ((r % 2) == 0) {
      cout << " IS COOL" << endl;
   } else {
      cout << " IS NOT COOL" << endl;
   }
}