#include <iostream>
using namespace std;

/**
 * PRE:
 * POST: retuns if n is a prime number or doesn't
*/
bool is_prime(int n);

int main() {
   int x;
   
   while (cin >> x and is_prime(x)) {
      int y = x + 1;
      
      while (not is_prime(y)) ++y;
      cout << y << endl;
   }
}

bool is_prime(int n) {
   if (n < 2) return false;
   for (int i = 2; i*i <= n; ++i) {
      if (n%i == 0) return false;
   }
   return true;
}