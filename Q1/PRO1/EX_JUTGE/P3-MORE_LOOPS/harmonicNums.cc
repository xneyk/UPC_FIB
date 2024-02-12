#include <iostream>
using namespace std;

int main() {
   cout.setf(ios::fixed);
   cout.precision(10);

   int n, m;
   
   while (cin >> n >> m) {
      double r = 0;
      for (int i = m + 1; i <= n; ++i){
         r = r + (1.0 / i);
      }
      cout << r << endl;
   }
}