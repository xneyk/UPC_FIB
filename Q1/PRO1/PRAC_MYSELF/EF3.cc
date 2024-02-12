#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

int main() {
   int n, m;
   while (cin >> n >> m) {
      Matrix matrix (n, Row (m));

      char c;
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) {
            cin >> c;
            matrix[i][j] = int (c - '0');
         }
      }

      int row_counter = 0;
      for (int i = 0; i < n; ++i) {
         int checker = 45; // 45 = 1+2+3+4+5+6+7+8+9
         for (int j = 0; j < m; ++j) {
            checker -= matrix[i][j];
            if (j >= 9) checker += matrix[i][j-9];
            if (checker == 0) ++ row_counter;
         }
      }
      
      int column_counter = 0;
      for (int i = 0; i < m; ++i) {
         int checker = 45; // 45 = 1+2+3+4+5+6+7+8+9
         for (int j = 0; j < n; ++j) {
            checker -= matrix[j][i];
            if (j >= 9) checker += matrix[j-9][i];
            if (checker == 0) ++ column_counter;
         }
      }

      cout << row_counter << ' ' << column_counter << endl;
   }
}