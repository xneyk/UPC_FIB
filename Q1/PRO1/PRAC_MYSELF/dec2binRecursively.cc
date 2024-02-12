#include <iostream>
using namespace std;

void bin(int n) {
   if (n >= 2) bin(n / 2);
   cout << n % 2 << endl;
}

int main() {
   int x;
   cin >> x;
   bin(x);
}