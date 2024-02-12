#include <cmath>
#include <iostream>
using namespace std;

int main() {
   cout.setf(ios::fixed);
   cout.precision(6);

   double deg; // angle in dergrees.
   
   while(cin >> deg) {
      double rad = deg * (M_PI / 180); // deg --> rad conversion
      cout << sin(rad) << ' ' << cos(rad) << endl;
   }
}