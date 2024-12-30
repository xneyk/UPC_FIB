#include <iostream>
#include <vector>
using namespace std;

void binary(int i, int n, vector<int> &A) {
   if (i == n) { // imprimeix solucio 
      for (int i = 0; i < n; ++i) {
         cout << A[i];
         if(i < n - 1) cout << ' ';
      }
      cout << endl;
   } else {
      A[i] = 0; // branca de posar un 0.
      binary(i+1, n, A);
      A[i] = 1; // branca de posar un 1.
      binary(i+1, n, A);
   }
}

void binary(int n) {
   vector<int> A(n);
   binary(0, n, A);
}

int main() {
   int n;
   cin >> n;
   binary(n);
}