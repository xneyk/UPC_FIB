#include <iostream>
using namespace std;

void rec_word (int n) {
   if (n <= 0) cout << '0';
   else {
      for (int i = 0; i < n; ++i) {
         cout << n;
         rec_word(n-1);
      }
      cout << n;
   }
}

int main() {
   int n;
   while (cin >> n) {
      rec_word(n);
      cout << endl;
   }
}