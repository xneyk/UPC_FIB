#include <iostream>
#include <vector>
using namespace std;

void permutations(int i, int n, vector<int> &A, vector<bool> &used) {
   if (i == n) {
      cout << '(';
      for (int j = 0; j < n; ++j) {
         cout << A[j];
         if (j < n - 1) cout << ',';
      }
      cout << ')' << endl;
   } else {
      for (int j = 1; j <= n; ++j) {
         if (!used[j-1]) {
            A[i] = j;
            used[j-1] = true;
            permutations(i+1, n, A, used);
            used[j-1] = false;
         }
      }
   }
}

void permutations(int n) {
   vector<int> A(n, 0);
   vector<bool> used(n, false);

   permutations(0, n, A, used);
}

int main() {
   int n;
   cin >> n;

   permutations(n);
}