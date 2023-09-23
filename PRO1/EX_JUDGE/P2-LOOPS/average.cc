#include <iostream>
using namespace std;

int main() {
   cout.setf(ios::fixed);
   cout.precision(2);

   double n, r;
   int i = 0;
   
   r = 0;

   while ((cin >> n) and (n > 0)) {
      r += n;
      ++i;
   }
   cout << (r / i) << endl;
}