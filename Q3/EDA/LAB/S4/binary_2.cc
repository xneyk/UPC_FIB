#include <iostream>
#include <vector>
using namespace std;

void binary(int i, int n, int current_o, int o, vector<int> &A) {
   if (i == n) { // imprimeix solucio 
      for (int i = 0; i < n; ++i) {
         cout << A[i];
         if(i < n - 1) cout << ' ';
      }
      cout << endl;
   } else {
      if (i - current_o < n - o) {
         A[i] = 0; // branca de posar un 0.
         binary(i+1, n, current_o, o, A);
      }
      if (current_o < o) {
         A[i] = 1; // branca de posar un 1.
         binary(i+1, n, current_o+1, o, A);
      }
   }
}

void binary(int n, int o) {
   vector<int> A(n);
   binary(0, n, 0, o, A);
}

int main() {
   int n, o;
   cin >> n >> o;
   binary(n, o);
}