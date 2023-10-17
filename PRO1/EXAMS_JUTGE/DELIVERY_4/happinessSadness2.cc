#include <iostream>
using namespace std;

int main() {
   int happiness = 0;
   int sadness = 0;
   char c1, c2, c3;

   cin >> c1 >> c2;
   while (cin >> c3){
      if (not (c2 == '-' and c3 == '-')) {
         if (c1 == ':' and c2 == '-') {
            if (c3 == ')') ++happiness;
            else if (c3 == '(') ++sadness;
         }
         else if (c1 == '(' and c2 == '-' and c3 == ':') ++happiness;
         else if (c1 == ')' and c2 == '-' and c3 == ':') ++sadness;
         
         c1 = c2;
         c2 = c3;
      }

   }
   cout << happiness << ' ' << sadness << endl;
}