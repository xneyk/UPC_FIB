#include <iostream>
using namespace std;

int main() {
   int n, m;
   bool firstRectangle = true;
   
   while (cin >> n >> m) {
      if (not firstRectangle) cout << endl;
      int d = 9;
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) {
            if (d < 0) d = 9;
            cout << d;
            --d;
         }
         cout << endl;
      }
      firstRectangle = false;
   }
}