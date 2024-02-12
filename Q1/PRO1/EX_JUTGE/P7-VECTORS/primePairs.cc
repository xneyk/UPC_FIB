// P85480 Pairs of a sequence (1)
#include <iostream>
#include <vector>
using namespace std;


/**
 * PRE:  n is a natural number
 * POST: returns true if it's prime, false in other case.
*/
bool is_prime(int n) {
   if (n < 1) return false;
   for (int i = 2; i*i <= n; ++i) {
      if (n%i == 0) return false;
   }
   return true;
}

/**
 * PRE:  v is a vector of size n
 * POST: ini vector with the values set by console.
*/
void ini_v(vector<int>& v, int n) {
   for (int i = 0; i < n; ++i) {
      cin >> v[i];
   }
}
/**
 * PRE:  v is a vector of size n
 * POST: returns if it is possible to find two elements x_i and x_j
 *       (with i ≠ j) such that x_i + x_j is a prime number.
*/
bool search_prime_pair(vector <int> v, int n) {
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         if (j != i and is_prime(v[i] + v[j])) return true;
      }
   }
   return false;
}

int main() {
   int n;
   while (cin >> n) {
      vector<int> v(n);
      ini_v(v, n);
      if (search_prime_pair(v, n)) cout << "yes" << endl;
      else cout << "no" << endl;
   }
}