#include <iostream>
using namespace std;

int main() {
   int n;
   
   while (cin >> n) {
      cout << "The sum of the digits of " << n << " is ";
      
      int r = 0;
      while (n > 0) {
         r += n % 10;
         n /= 10;
      }
      cout << r << '.' << endl;
   }
}