#include <iostream>
using namespace std;

int main() {
   cout.setf(ios::fixed);
   cout.precision(4);

   double c, i; 
   int t;
   string interest_type;

   cin >> c >> i >> t >> interest_type;
   
   i /= 100; // Conversio % en tant per 1;
   
   if (interest_type == "simple") {
      c += c * i * t;
      cout << c << endl;
   } else {
      for (int j = 1; j <= t; ++j) {
         c += c * i;
      }
      cout << c << endl;
   }
}