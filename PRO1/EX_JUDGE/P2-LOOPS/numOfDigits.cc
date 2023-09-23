#include <iostream>
using namespace std;

int main() {
   int n;
   int digits = 0;
   cin >> n;

   cout << "The number of digits of " << n << " is ";

   if(n != 0){
      while(n != 0){
         n = n/10;
         ++digits;
      }
   } else {
      digits = 1;
   }

   cout << digits << '.' << endl;
}