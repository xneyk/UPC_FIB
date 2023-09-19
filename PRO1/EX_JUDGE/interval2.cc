#include <iostream>
using namespace std;

int main() {
   int a1, b1, a2, b2;
   cin >> a1 >> b1 >> a2 >> b2;

   if((a1 >= a2 and b1 <= b2) or (a2 >= a1 and b2 <= b1)){
      // Algun dels intervals es troba dins de l'altre
      if(not (a1 == a2 and b1 == b2)){
         // Si no son iguals entra al condicional
         if((a1 >= a2 and b1 <= b2)){
            cout << '1' << endl;
         } else {
            cout << '2' << endl;
         }
      } else {
         cout << '=' << endl;
      }
   } else {
      cout << '?' << endl;
   }
}