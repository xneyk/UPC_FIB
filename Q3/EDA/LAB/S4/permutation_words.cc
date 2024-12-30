#include <iostream>
#include <vector>
using namespace std;

void permutations(int i, int n, vector<string> &words, vector<string> &A, vector<bool> &used) {
   if (i == n) {
      cout << '(';
      for (int j = 0; j < n; ++j) {
         cout << A[j];
         if (j < n - 1) cout << ',';
      }
      cout << ')' << endl;
   } else {
      for (int j = 0; j < n; ++j) {
         if (!used[j]) {
            A[i] = words[j];
            used[j] = true;
            permutations(i+1, n, words, A, used);
            used[j] = false;
         }
      }
   }
}

void permutations(int n, vector<string> &words) {
   vector<string> A(n);
   vector<bool> used(n, false);

   permutations(0, n, words, A, used);
}

int main() {
   int n;
   cin >> n;
   vector<string> words(n);
   for (int i = 0; i < n; ++i) cin >> words[i];

   permutations(n, words);
}