//X10495 Second biggest column
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

bool biggerThan(Row a, Row b) {
   int i = 0; 
   int l = a.size() - 1; // a and b have same size.
   while (a[i] == b[i] and i < l) ++i;
   return a[i] > b[i];
}

int main() {
   int n, m;
   while (cin >> n >> m) {
      Matrix matrix(m, Row (n));
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) cin >> matrix[j][i];
      }
      sort(matrix.begin(), matrix.end(), biggerThan);
      
      for (int i = 0; i < n; ++i) {
         int j = 0;
         if (m > 1) j = 1;

         cout << matrix[j][i];
         if (i < n-1) cout << ' ';
         else cout << endl;
      }
      cout << endl;
   }
}