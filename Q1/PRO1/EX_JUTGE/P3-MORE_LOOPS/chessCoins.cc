#include <iostream>
using namespace std;

int main() {
   int r, c;
   int total_coins = 0;
   cin >> r >> c;

   for (int i = 0; i < r; ++i) {
      char coin;
      for (int j = 0; j < c; ++j) {
         cin >> coin;
         total_coins += int(coin) - int('0');
      }
   }
   cout << total_coins << endl;
}