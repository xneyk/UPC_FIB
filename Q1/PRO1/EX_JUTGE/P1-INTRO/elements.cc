#include <iostream>
using namespace std;

int main() {
   char a, b;
   cin >> a >> b;

   if (a != b) {
      if (a == 'A'){
         if (b == 'P') cout << '1'<< endl;
         else cout << '2' << endl;
      }
      if (a == 'P'){
         if (b == 'V') cout << '1'<< endl;
         else cout << '2' << endl;
      }
      if (a == 'V'){
         if (b == 'A') cout << '1'<< endl;
         else cout << '2' << endl;
      }
   } else {
      cout << '-' << endl;
   }
}