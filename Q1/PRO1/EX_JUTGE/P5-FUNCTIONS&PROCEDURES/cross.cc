#include <iostream>
using namespace std;

// PRE: n ≥ 3, n is odd.
void cross(int n, char c);

/**
 * PRE: n ≥ 3, n is odd.
 * POST: Prints half vertical of a cross n x n;
*/
void vertical(int n, char c);

int main() {
   int n;
   char c;
   while (cin >> n >> c) cross(n, c);
}

void vertical(int n, char c) {
   for (int i = 0; i < n/2; ++i) {
      for (int j = 0; j <= n/2; ++j) {
         if (j < n/2) cout << ' ';
         else cout << c << endl;
      }
   }
}

void cross(int n, char c) {
   vertical(n,c);
   for (int j = 0; j < n; ++j) cout << c; // Horitzontal
   cout << endl;
   vertical(n,c);
}