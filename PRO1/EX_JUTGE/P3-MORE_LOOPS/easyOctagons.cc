#include <iostream>
using namespace std;

int main() {
   int n;
   
   while ((cin >> n) and (n >= 2)){
      int c = n;
      for (int i = 1; i <= (n - 1); ++i){
         for (int j = 1; j <= n - i; ++j){
            cout << ' ';
         }
         for (int k = 1; k <= c; ++k){
            cout << 'X';
         }
         c += 2;
         cout << endl;
      }
      for (int l = 1; l <= n; ++l){
         for (int m = 1; m <= (3 * n - 2); ++m) cout << 'X';
         cout << endl;
      }
      --c;
      for (int i = (n - 1); i >= 1; --i){
         for (int j = n - i; j >= 1; --j){
            cout << ' ';
         }
         for (int k = 1; k < c; ++k){
            cout << 'X';
         }
         c -= 2;
         cout << endl;
      }
      cout << endl;
   }
}