//P87920 Equal to the sum of the rest (II)
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int n;
   while (cin >> n) {
      vector<int> v(n);
      int total = 0;

      for (int i = 0; i < n; ++i) { // Lectura y calculo del total
         cin >> v[i];
         total += v[i];
      }

      bool found = false;
      int i = 0;
      while (i < n and not found) {
         if (v[i] == total - v[i]) found = true; // Comparamos con el total menos el mismo
         ++i;
      }

      if (found) cout << "YES" << endl;
      else cout << "NO" << endl;
   }
}