#include <iostream>
using namespace std;

bool is_palindromic(int n);

int main() {
   int x;
   while (cin >> x) cout << is_palindromic(x) << endl;
}

bool is_palindromic(int n) {
   int ini_n =  n;
   int reversed_n = 0;
   while (n > 0) {
      reversed_n = reversed_n*10 + n%10;
      n /= 10;
   }
   return ini_n == reversed_n;
}