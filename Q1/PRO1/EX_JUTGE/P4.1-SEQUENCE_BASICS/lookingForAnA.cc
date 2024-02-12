#include <iostream>
using namespace std;

int main() {
   char c;
   bool found = false;

   while ((not found) and (cin >> c) and (c != '.')) {
      if (c == 'a') found = true;
   }
   if (found) cout << "yes" << endl;
   else cout << "no" << endl;
}