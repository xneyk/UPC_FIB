#include <iostream>
using namespace std;

int n_digits(int n);
bool is_palindromic(int n);

int main() {
   int x;
   while (cin >> x) cout << n_digits(x) << endl;
}

int n_digits(int n) {
   if (n == 0) return 1;

   int i = 0;
   while (n > 0) {
      n /= 10;
      ++i;
   }
   return i;
}

bool is_palindromic(int n) {
   int digits = n_digits(n);
   int shifter = 1; // emmagatzema per on s'ha de tallar el numero.
   for (int i = 0; i < (digits / 2); ++i) shifter *= 10;

   int second_half = n % shifter;
   n /= shifter;

   // for (int i = 0; i < (digits / 2); ++i)
}