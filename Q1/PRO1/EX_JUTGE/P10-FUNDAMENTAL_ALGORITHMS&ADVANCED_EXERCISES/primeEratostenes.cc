//P89124 Sieve of Eratosthenes
#include <iostream>
#include <vector>
using namespace std;

/**
 * PRE: n <= 0
 * POST: returns the Sieve of Eratosthenes of n.
*/
vector<bool> create_eratosthenes(int n) {
   vector<bool> v(n+1, true);
   v[0] = v[1] = false;
   for (int i = 2; i*i <= n; ++i) {
      if (v[i]) {
         for (int j = i*i; j <= n; j += i) {
            v[j] = false;
         }
      }
   }
   return v;
}

int main() {
   int n;
   vector<bool> eratosthenes = create_eratosthenes(1000000); // 10^6 max input.

   while (cin >> n) {
      if (eratosthenes[n]) cout << n << " is prime" << endl;
      else cout << n << " is not prime" << endl;
   }
}