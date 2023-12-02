//P51222 - Recursive number of digits
#include <iostream>
using namespace std;

int number_of_digits(int n);

int main() {
   int x;
   while (cin >> x) cout << number_of_digits(x) << endl;
}

int number_of_digits(int n) {
   if (n <= 9) return 1;
   else return 1 + number_of_digits(n/10);
}