//P89407 F004B. Stable products
#include <iostream>
#include <vector>
using namespace std;

/**
 * PRE: x is a natural number, n is the base to convert.
 * POST: prints x in base n.
*/
void print_base_n(int x, int n) {
   if (x >= n) print_base_n(x/n, n);

   if (10 <= x%n and x%n < n) cout << char('A' + x%n - 10);
   else cout << x%n;
}

/**
 * PRE:  x is a natural number, n is the base to convert 2 <= n <= 16. counter is a vector of lenght n.
 * POST: each slot of the vector has the number of occurrences of the digit represented by its index.
*/
void count_base_n(vector<int>& counter, int x, int n) {
   if (x < n) ++counter[x];
   else {
      ++counter[x%n];
      count_base_n(counter, x/n, n);
   }
}

/**
 * PRE: v and w are vectors with the same lenght n.
 * POST: returns true if v[0] == w[0], v[1] == w[1], ... v[n-1] == w[n-1], false otherwise.
*/
bool cmp_eq(const vector<int>& v, const vector<int>& w, int n) {
   for (int i = 0; i < n; ++i) {
      if (v[i] != w[i]) return false;
   }
   return true;
}

int main() {
   int x, y;
   while (cin >> x >> y) {
      bool exists = false;
      
      cout << "solutions for " << x << " and " << y << endl;
      for (int i = 2; i <= 16; ++i) {
         vector<int> x_y_dig(i);
         // we are passing the same vector reference
         // it will acumulate the sum of occurrences of the digits of x and occurrences of the digits of y
         count_base_n(x_y_dig, x, i);
         count_base_n(x_y_dig, y, i);

         vector<int> x_mul_y_dig(i);
         count_base_n(x_mul_y_dig, x*y, i);

         if (cmp_eq(x_y_dig, x_mul_y_dig, i)) {
            exists = true;
            print_base_n(x, i);
            cout << " * ";
            print_base_n(y, i);
            cout << " = ";
            print_base_n(x*y, i);
            cout << " (base " << i << ")" << endl;
         }
      }
      if (!exists) cout << "none of them" << endl;
      
      cout << endl;
   }
}