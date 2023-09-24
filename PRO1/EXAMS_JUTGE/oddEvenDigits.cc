#include <iostream>
using namespace std;

int main() {
   int x;

  while (cin >> x) {
   int y = 0;
   int z = 0;
   
   /**
    * Amb intencio d'estalbiar memoria, els nombres senars s'asignaran a "z"
    * i els parells a "y". Posteriorment, el resultat final sera montat a "y"
    * i "z" es reasignara a "2y".
   */
   
   while (x > 0) {
      if((x % 10) != 0) {
         if((x % 10) % 2 != 0 ) {
            // Es senar
            y = (y * 10) + (x % 10);
         } else {
            // Es parell
            z = (z * 10) + (x % 10);
         }
      }
      x /= 10;
   }

   while (y > 0) {
      x = (10 * x) + (y % 10);
      y /= 10;
   }
   
   y = x;

   while (z > 0) {
      y = (10 * y) + (z % 10);
      z /= 10;
   }

   cout << y << ' ' << (2 * y) << endl;
  }
}