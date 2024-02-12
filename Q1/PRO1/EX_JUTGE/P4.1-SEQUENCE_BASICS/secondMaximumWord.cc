#include <iostream>
using namespace std;

int main() {
   string word, prev_max, max;
   
   cin >> word;
   max = word;

   while (cin >> word) {
      if (word > prev_max and word < max) prev_max = word;
      if (word > max) {
         prev_max = max;
         max = word;
      }
   }
   cout << prev_max << endl;
}