#include <iostream>
using namespace std;

int main() {
   int n, m;

   while (cin >> n >> m) {
      if (m != 0) {
         int r = n;
         
         for (int i = 1; i < m; ++i) {
            r *= n;
         }
         cout << r << endl;
      } else {
         cout << 1 << endl;
      }
   }
}