// X39187
#include <iostream>
#include <vector>

using namespace std;

void transactions(int idx, const int n, int current_c, const int c, vector<char> transaction) {
   if (idx == n) {
      for (char action : transaction) cout << action;
      cout << endl;
   } else {
      if (current_c > 0) {
         transaction[idx] = 'b';
         // all possible transactions by buying at idx moment
         transactions(idx+1, n, current_c-1, c, transaction);
      }
      // the diference between initial coins and current coins are shares we have
      if (c - current_c > 0) {
         transaction[idx] = 's';
         // all possible transactions by selling at idx moment.
         transactions(idx+1, n, current_c+1, c, transaction);
      }
   }
}

void transactions(int n, int c) {
   vector<char> transaction(n);
   transactions(0, n, c, c, transaction);
}

int main() {
   int n, c;
   cin >> n >> c;
   transactions(n, c);
}