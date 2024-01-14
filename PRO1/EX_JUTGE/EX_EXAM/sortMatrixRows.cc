//X69097 Sort matrix rows
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

bool biggerThan(Row a, Row b) {
   int i = 1;
   int l = a.size() - 1; // a and b have same size.
   if (a[0] != b[0]) return a[0] < b[0]; //diferent sign

   //Have same sign (a[0] = b[0]).
   while (i < l and a[i] == b[i]) ++i;
   if (a[0] == 0) return a[i] > b[i]; //positive numbers
   else return a[i] < b[i]; //negative numbers
}

int main() {
   int n, m;
   while (cin >> n >> m) {
      Matrix matrix(n, Row (m));
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) cin >> matrix[i][j];
      }
      sort(matrix.begin(), matrix.end(), biggerThan);

      //Print Matrix Result
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) {
            cout << matrix[i][j];
            if (j < m - 1) cout << ' ';
            else cout << endl;
         }
      }
      cout << endl;
   }
}