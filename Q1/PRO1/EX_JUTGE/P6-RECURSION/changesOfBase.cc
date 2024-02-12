//P56549 Changes of base
#include <iostream>
using namespace std;

/**
 * PRE: x is a natural number, n is the base to convert.
 * POST: prints x in base n.
*/
void base_n(int x, int n);

int main() {
   int x;
   while (cin >> x) {
      cout << x << " = ";
      base_n(x, 2);
      cout << ", ";
      base_n(x,8);
      cout << ", ";
      base_n(x,16);
      cout << endl;
   }
}

void base_n(int x, int n) {
   if (x >= n) base_n(x/n, n);

   if (10 <= x%n and x%n < n) cout << char('A' + x%n - 10);
   else cout << x%n;
}