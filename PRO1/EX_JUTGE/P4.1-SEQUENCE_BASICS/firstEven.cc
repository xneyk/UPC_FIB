#include <iostream>
using namespace std;

int main() {
   int n;
   int i = 0;
   bool found = false;

   while ((not found) and (cin >> n)) {
      if (n % 2 == 0) found = true;
      ++i;
   }
   if (found) cout << i << endl;
}