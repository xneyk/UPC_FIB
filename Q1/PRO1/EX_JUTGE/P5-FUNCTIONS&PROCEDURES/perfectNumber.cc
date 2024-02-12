#include <iostream>
using namespace std;

/**
 * PRE: n is a natural number.
*/
bool is_perfect(int n);

int main() {
   int x;
   while (cin >> x) cout << is_perfect(x) << endl;
}

bool is_perfect(int n) {
   int res = 1;
   for (int i = 2; i*i <= n; ++i) {
      if (n%i == 0) res += i + n/i;
   }

   return (res == n and n > 1);
}