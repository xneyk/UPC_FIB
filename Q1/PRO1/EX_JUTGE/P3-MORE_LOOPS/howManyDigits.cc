#include <iostream>
using namespace std;

int main() {
   int n, b;

   while (cin >> b >> n) {
      int k = n; // Donde k es una copia de n.
      int d = 0; // Donde d es el numero de digitos.

      if(k != 0){
         while(k != 0){
            k = k/b;
            ++d;
         }
      } else {
         d = 1;
      }
      cout << d << endl;
   }
}