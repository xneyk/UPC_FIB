#include <iostream>
using namespace std;

int main() {
   int n;
   int last_increasing = 0;
   int current_line = 1;

   while (cin >> n) {
      string prev_word, word;
      bool increasing = true;
      for (int i = 1; i <= n; ++i) {
         cin >> word;

         if (i == 1) prev_word = word;
         else if (prev_word > word) increasing = false;

         prev_word = word;
      }
      
      if (increasing) {
         last_increasing = current_line;
      }
      
      ++current_line;
   }
   if (last_increasing > 0) cout << "The last line in increasing order is " << last_increasing << '.' << endl;
   else cout << "There is no line in increasing order." << endl;
}