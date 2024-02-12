//X50141 Function to fatten numbers
#include <iostream>
using namespace std;

/**
 * PRE: x is a natual number
 * POST: if x digist are ==> x1,x2,...xn, returns max(x1,x2,...,xn)
*/
int max_digit(int x);
int fatten(int x);

int main() {
   int x;
   while (cin >> x) cout << fatten(x) << endl;
}

int max_digit(int x) {
   int max = 0;
   while (x > 0) {
      if (x%10 >= max) max = x%10;
      x /= 10;
   }
   return max;
}

int fatten(int x) {
   if (x <= 9) return x;
   else return fatten(x/10) * 10 + max_digit(x);
}