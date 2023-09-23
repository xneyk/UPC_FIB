#include <iostream>
using namespace std;

int main() {
   int n;
   cin >> n;
   
   for(int i = 2; i <= 16; ++i){
      // Este codigo se repite por cada una de las 15 bases.
      int k = n; // Donde k es una copia de n.
      int d = 0; // Donde d es el numero de digitos.

      if(k != 0){
         while(k != 0){
            k = k/i;
            ++d;
         }
      } else {
         d = 1;
      }
      cout << "Base " << i << ": " << d << " cifras." << endl;
   }
}