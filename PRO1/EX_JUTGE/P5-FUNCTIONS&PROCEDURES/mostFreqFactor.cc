#include <iostream>
using namespace std;

void factor(int n, int &f, int &q);

int main() {
   int n;
   while (cin >> n) {
      int f = -1, q = 1000;
      factor(n, f, q);
      cout << f << ' ' << q << endl;
   }
   return 0;
}

void factor(int n, int &f, int &q) {
   int d = 2;
   int x = q = 0;
   
   while (d*d <= n) { // LOOP pels divisors
      x = 0;
      while (n%d == 0) { // LOOP pel quants cops es divisor
         ++x;
         n /= d;
         if (x > q) {
            q = x;
            f = d;
         }
      } 
      ++d;
   }
   
   if (q == 0) { // n --> primer
      f = n;
      q = 1;
   }
}