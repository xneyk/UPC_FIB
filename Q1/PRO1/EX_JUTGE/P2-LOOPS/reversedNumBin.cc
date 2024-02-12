#include <iostream>
using namespace std;

int main() {
   int n;
   cin >> n;
   
   // No cal donar-li la volta ja que el resultat de dividir-lo d'aquesta
   // manera ja resulta el numero amb la xifra de mes pes a la dreta i la
   // de menys pes a l'esquerra.

   if (n != 0) {
      while (n != 0) {
         cout << (n % 2);
         n = n/ 2;
      }
   } else {
      cout << 0;
   }
   cout << endl;
}