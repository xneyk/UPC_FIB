#include <iostream>

using namespace std;

void recursive(int n, int ini_n);

int main() {
   int x;
   while (cin >> x) {
      recursive(x, x);
      cout << endl;
   }
}

void recursive(int n, int ini_n) {
   int z = 2;
   int dir = 1;

   if (n == 1) {
      for(int i = 0; i < (ini_n - n); ++i) cout << ' ';
      cout << '*' << endl;
   } else {
      recursive(n - 1, ini_n);
      
      for (int i = 0; i < (2*n - 3); ++i) {
         for(int j = 0; j < (ini_n - z); ++j) cout << ' ';
         for (int j = 0; j < (2*z - 1); ++j) cout << '*';
         cout << endl;

         if (dir == -1 and z == 2) dir = 1;
         else if (dir == 1 and z == n) dir = -1;
         z += dir;
      }

      recursive(n - 1, ini_n);
   }
}