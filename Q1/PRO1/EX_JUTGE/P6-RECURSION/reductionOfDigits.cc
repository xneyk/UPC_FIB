//P96965 Reduction of digits
#include <iostream>
using namespace std;

/**
 * PRE: x is a natural number;
*/
int sum_of_digits(int x);
int reduction_of_digits(int x);

int main() {
   int x;
   while (cin >> x) cout << reduction_of_digits(x) << endl;
}

int sum_of_digits(int x) {
   if (x <= 9) return x;
   else return sum_of_digits(x/10) + x%10;
}

int reduction_of_digits(int x) {
   if (x <= 9) return x;
   else return reduction_of_digits(sum_of_digits(x));
}