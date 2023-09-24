#include <iostream>
using namespace std;

int main() {
   int n;
   cin >> n;
   
   // No cal donar-li la volta ja que el resultat de dividir-lo d'aquesta
   // manera ja resulta el numero amb la xifra de mes pes a la dreta i la
   // de menys pes a l'esquerra.

   if (n != 0) {
      int k; // On k es la propera xifra que s'afegeix a la traducció a base hexadecimal
      while (n != 0) {
         k = (n % 16);
         if (not (k < 10)) {
            if(k == 10) cout << 'A';
            if(k == 11) cout << 'B';
            if(k == 12) cout << 'C';
            if(k == 13) cout << 'D';
            if(k == 14) cout << 'E';
            if(k == 15) cout << 'F';
         } else {
            cout << k;
         }
         n = n / 16;
      }
   } else {
      cout << 0;
   }
   cout << endl;
}