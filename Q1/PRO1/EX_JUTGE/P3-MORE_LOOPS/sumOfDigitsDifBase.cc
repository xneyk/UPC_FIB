#include <iostream>
using namespace std;

int main() {
   int n, b;

   cin >> b;

   while (cin >> n) {
      cout << n << ": ";
      
      int r = 0;
      while (n > 0) {
         r += n % b;
         n /= b;
      }
      cout << r << endl;
   }
}