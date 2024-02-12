#include <iostream>
#include <vector>
using namespace std;

typedef vector<string> Char_Matrix;

/**
 * PRE: Les files son strings de tamany regular (tots el mateix tamany (columns))
*/
void ini_matrix (Char_Matrix& matrix, int rows);

int search_posibles(Char_Matrix& matrix, int rows, int columns);

int main() {
   int rows, columns;
   while (cin >> rows >> columns) {
      Char_Matrix m(rows);
      ini_matrix(m, rows);
      cout << search_posibles(m, rows, columns) << endl;
   }
}

void ini_matrix (Char_Matrix& matrix, int rows) {
   string s;
   for (int i = 0; i < rows; ++i) {
      cin >> s;
      matrix[i] = s;
   }
}

int search_submatrix(Char_Matrix& matrix, int ini_i, int ini_j, int end_i, int end_j, char to_find) {
   int n = 0;
   for (int i = ini_i; i < end_i; ++i) {
      for (int j = ini_j; j < end_j; ++j) {
         if (matrix[i][j] == to_find) {
            ++n;
         }
      }
   }

   return n;
}

int search_posibles(Char_Matrix& matrix, int rows, int columns) {
   int posibilities = 0;
   for (int i = 1; i < (rows - 1); ++i) {
      for (int j = 1; j < (columns - 1); ++j) {
         if (matrix[i][j] == '-') {
            posibilities += search_submatrix(matrix, 0, 0, i, j, ':') * search_submatrix(matrix, i+1, j+1, rows, columns, ')');
         }
      }
   }
   return posibilities;
}