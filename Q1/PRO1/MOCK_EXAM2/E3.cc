#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;
typedef vector<int> Ocurrences;

void add_ocurrence(vector<Ocurrences>& row_counter, vector<Ocurrences>& column_counter, int x, int i, int j) {
   ++row_counter[i][x];
   ++column_counter[j][x];
}

void ini_matrix(Matrix& v, int n, int m, vector<Ocurrences>& row_counter, vector<Ocurrences>& column_counter) {
   char c;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> c; // l'input son type char.
         v[i][j] = c - '0'; // omplim la matriu amb el digit equivalent al char.
         add_ocurrence(row_counter, column_counter, v[i][j], i, j);
      }
   }
}

int main() {
   int n, m;
   while (cin >> n >> m) {
      vector<Ocurrences> row_counter(n, Ocurrences(10, 0));
      vector<Ocurrences> column_counter(m, Ocurrences(10, 0));
      Matrix u(n, Row (m));
      ini_matrix(u, n, m, row_counter, column_counter);
      
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) {
            int x = u[i][j];
            cout << (row_counter[i][x] + column_counter[j][x])%10;
         }
         cout << endl;
      }
      cout << endl;
   }
}