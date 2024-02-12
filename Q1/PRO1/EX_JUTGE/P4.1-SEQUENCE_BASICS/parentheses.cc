#include <iostream>
using namespace std;

int main() {
   char c;
   int i = 0;
   bool can_close = true;

   while (can_close and cin >> c) {
      if (c == '(') ++i;
      else --i;
      if (i <= -1) can_close = false;
   }
   if (can_close and i == 0) cout << "yes" << endl;
   else cout << "no" << endl;
}