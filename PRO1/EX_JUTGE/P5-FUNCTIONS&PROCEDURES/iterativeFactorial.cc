#include <iostream>
using namespace std;

int factorial(int n);

int main() {
   int x;
   while (cin >> x) cout << factorial(x) << endl;
}

int factorial(int n) {
   int result = 1;
   for (int i = 1; i <= n; ++i) result *= i;
   return result;
}