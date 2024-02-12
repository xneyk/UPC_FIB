//P22467 Perfect primes
#include <iostream>
using namespace std;

/**
 * PRE: x is a natural number;
*/
int sum_of_digits(int x);
bool is_prime(int n);
bool is_perfect_prime(int n);

int main() {
   int x;
   while (cin >> x) {
      is_perfect_prime(x) ? cout << "true" : cout << "false";
      cout << endl;
   }
}

int sum_of_digits(int x) {
   if (x <= 9) return x;
   else return sum_of_digits(x/10) + x%10;
}

bool is_prime(int n) {
   if (n < 2) return false;
   for (int i = 2; i*i <= n; ++i) {
      if (n%i == 0) return false;
   }
   return true;
}

bool is_perfect_prime(int n) {
   if (n <= 9) return is_prime(n);
   else return is_prime(n) and is_perfect_prime(sum_of_digits(n));
}