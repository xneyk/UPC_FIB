#include <iostream>
using namespace std;

int main() {
   cout.setf(ios::fixed);
   cout.precision(2);

   int n;
   double x;
   double sum1 = 0;
   double sum2 = 0;

   cin >> n;

   for (int i = 1; i <= n; ++i) {
      cin >> x;

      sum1 += (x*x);
      sum2 += x;
   }

   cout << (((1.0 / (n - 1)) * sum1) - ((1.0 / (n * (n - 1))) * (sum2*sum2))) << endl;
}