#include <iostream>
using namespace std;

int main() {
   int a, b;
   cin >> a >> b;

   for (int i = a; i <= b; ++i) {
      cout << i;
      if(not (i == b)){ // Si no es l'ultim numero del interval, afegeix la coma darrera.
         cout << ',';
      }
   }
   cout << endl;
}