#include <iostream>
using namespace std;

int sum_min_max(int x, int y, int z);

int main() {
   int x, y, z;
   while (cin >> x >> y >> z) cout << sum_min_max(x, y, z);
}

int sum_min_max(int x, int y, int z) {
   int max = 0;
   int min = 0;

   if (x > y) {
      max = x;
      min = y;
   } else {
      max = y;
      min = x;
   }

   if (z > max) max = z;
   else if (z < min) min = z;

   return (max + min);
}