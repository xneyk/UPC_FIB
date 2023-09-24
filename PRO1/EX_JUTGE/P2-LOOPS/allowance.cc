#include <iostream>
using namespace std;

int main() {
   int d, n, t;
   int r = 0;
   // On d despeses fixes, n estalbis inicials, t numero de setmanes.
   // r el numero de setmanes amb saldo estrictament possitiu.
   cin >> d >> n >> t;

   for (int i = 1; i <= t; ++i) {
      int a;
      cin >> a;
      
      n = (n + a) - d;

      if(n > 0) ++r;
   }

   cout << r << endl;
}