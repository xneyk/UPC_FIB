#include <iostream>
using namespace std;

int main() {
   int y, d, h, m, s;
   cin >> y >> d >> h >> m >> s;

   // Conversió en cascada d'anys a dies, de dies a hores, ... fins acumular els segons totals.
   d = d + (y * 365);
   h = h + (d * 24);
   m = m + (h * 60);
   s = s + (m * 60);

   cout << s << endl;
}