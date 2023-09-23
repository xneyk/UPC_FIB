#include <iostream>
using namespace std;

int main() {
   char a;
   int c = 0; // On c es un contador de lletres "a".

   while ((cin >> a) and (a != '.')) {
      if(a == 'a') ++c;
   }
   cout << c << endl;
}