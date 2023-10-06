#include <iostream>
using namespace std;

int main() {
   int n;
   
   while (cin >> n) {
      int p = 0;
      bool found = false;

      while (not found) {
         if(n != 1){
            if ((n % 2) == 0) {
               n /= 2;
            } else {
               n *= 3;
               ++n;
            }
            ++p;
         } else {
            found = true;
         }
      }
      cout << p << endl;
   }
}