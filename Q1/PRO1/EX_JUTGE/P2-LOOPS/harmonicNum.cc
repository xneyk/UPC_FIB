#include <iostream>
using namespace std;

int main() {
   cout.setf(ios::fixed);
   cout.precision(4);

   int n;
   double r = 0;
   cin >> n;

   for (int i = 1; i <= n; ++i){
      r = r + (1.0/i);
   }

   cout << r << endl;
}