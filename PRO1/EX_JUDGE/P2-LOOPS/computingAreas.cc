#include <iostream>
#include <cmath>
using namespace std;

int main() {
   cout.setf(ios::fixed);
   cout.precision(6);

   int n;
   string area;

   cin >> n;

   for(int i = 1; i <= n; ++i){
      cin >> area;

      if (area == "rectangle") {
         double l, w;
         cin >> l >> w;
         cout << l * w << endl;
      }

      if (area == "circle") {
         double r;
         cin >> r;
         cout << M_PI * (r*r) << endl;
      }
   }
}