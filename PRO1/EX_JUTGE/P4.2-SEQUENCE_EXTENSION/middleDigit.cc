#include <iostream>
using namespace std;

int main() {
   bool tie = true; // Partiremos de la hipotesis de que hasta que uno no pierda empatados.
   int n, middle_digit, i = 0;
   cin >> n;

   while (tie and i < 2*n) {
      int x, x_copy, j = 0;
      cin >> x;
      x_copy = x;

      if (x == 0) {
         j = 1;
      } else {
         while (x_copy > 0) {
            ++j;
            x_copy /= 10;
         }
      }

      for (int k = 0; k < (j / 2); ++k) x /= 10;

      if (i != 0) {
         if ((j % 2 == 0) or (x % 10 != middle_digit)) {
            if (i % 2 == 0) {
               tie = false;
               cout << 'B' << endl;
            } else {
               tie = false;
               cout << 'A' << endl;
            }
         }
      } else {
         if (j % 2 == 0) {
            tie = false;
            cout << 'B' << endl;
         }
         middle_digit = x % 10;
      }
      ++i;
   }
   if (tie) cout << '=' << endl;
}