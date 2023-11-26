#include <iostream>
using namespace std;

/**
 * PRE: 1 ≤ num ≤ 10^9 and 1 ≤ den ≤ 10^9
*/
void read_rational(int& num, int& den);

/**
 * PRE: a > b
*/
int mcd(int a, int b);

int main() {
   int num, den;
   read_rational(num, den);
   cout << num << ' ' << den << endl;
}


int mcd(int a, int b) {
   int res = b;
   b = a%b;
   a = res;
   while (b != 0) {
      res = b;
      b = a%b;
      a = res;
   }
   return res;
}

void read_rational(int& num, int& den) {
   int max_common_divider;
   char c; // Captura '/'.

   cin >> num >> c >> den;
   if (num > den) max_common_divider = mcd(num, den);
   else max_common_divider = mcd(den, num);

   num /= max_common_divider;
   den /= max_common_divider;
}