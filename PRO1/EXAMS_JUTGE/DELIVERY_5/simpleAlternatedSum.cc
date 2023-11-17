#include <iostream>
using namespace std;

// Pre: n >= 1
// Post: Returns 1-2+3-4+...+(-1)^(n+1)*n
int simpleAlternatedSum(int n);

int main() {
   int n;
   while (cin >> n) {
      cout << simpleAlternatedSum(n) << endl;
   }
}

// Base: n == 1 --> simpleAlternatedSum(1) = 1
// Recursive: n >= 1 --> simpleAlternatedSum(n) = simpleAlternatedSum(n - 1) +- n
int simpleAlternatedSum(int n) {
   if (n == 1) return 1;
   
   if (n % 2 == 0) return simpleAlternatedSum(n - 1) - n;
   else return simpleAlternatedSum(n - 1) + n;
}