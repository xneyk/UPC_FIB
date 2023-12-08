#include <iostream>
#include <vector>
using namespace std;

typedef vector<string> char_matrix;

/**
 * PRE: Les files son strings de tamany regular (tots el mateix tamany (columns))
*/
void ini_matrix (char_matrix& matrix, int rows);

/**
 * PRE: Rep tres caracters i compara si formen la submatriu es ":-)" o "(-:"
 * POST: Si es compleix la condicio augmenta el nombre de submatrius felices.
*/
void row_validation(int& n, char c1, char c2, char c3);

/**
 * PRE: Rep tres caracters i compara si formen la submatriu es " "|v " o " ^|" "
 * POST: Si es compleix la condicio augmenta el nombre de submatrius felices.
*/
void column_validation(int& n, char c1, char c2, char c3);

int main() {
   int rows, columns;
   while(cin >> rows >> columns) {
      int happy = 0;
      char_matrix m(rows);
      ini_matrix(m, rows);

      for (int i = 0; i < rows; ++i) {
         for (int j = 0; j < columns; ++j) {
            if (j + 2 < columns) row_validation(happy, m[i][j], m[i][j+1], m[i][j+2]);
            if (i + 2 < rows) column_validation(happy, m[i][j], m[i+1][j], m[i+2][j]);
         }
      }
      cout << happy << endl;
   }
}

void ini_matrix (char_matrix& matrix, int rows) {
   string s;
   for (int i = 0; i < rows; ++i) {
      cin >> s;
      matrix[i] = s;
   }
}

void row_validation(int& n, char c1, char c2, char c3) {
   if (c1 == '(' and c2 == '-' and c3 == ':') ++n;
   else if (c1 == ':' and c2 == '-' and c3 == ')') ++n;
}

void column_validation(int& n, char c1, char c2, char c3) {
   if (c1 == '"' and c2 == '|' and c3 == 'v') ++n;
   else if (c1 == '^' and c2 == '|' and c3 == '"') ++n;
}