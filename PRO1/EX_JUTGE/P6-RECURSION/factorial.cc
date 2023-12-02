// P12509 - recursive factorial
#include <iostream>
using namespace std;

int factorial(int n);

int main() {
   int x;
   while (cin >> x) cout << factorial(x) << endl;
}

int factorial(int n) {
   if (n <= 1) return 1;
   else return n*factorial(n - 1);
}