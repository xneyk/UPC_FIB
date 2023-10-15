#include <iostream>
using namespace std;

int main() {
   
   int n; // number of words
   int i = 0;
   bool found = false;
   
   while (not found and cin >> n) {
      int j = 1;
      bool increasing = true; // Supondremos que en un inicio la secuencia cumple la condicion
      string prev_word, word;

      if (n == 1) {
         found = true;
      } else {
         cin >> prev_word;
         while (j < n) {
            cin >> word;
            if (prev_word > word) increasing = false;
            prev_word = word;
            ++j;
         }
         if (increasing) found = true;
      }

      ++i;
   }
   if (found) cout << "The first line in increasing order is " << i << '.' << endl;
   else cout << "There is no line in increasing order." << endl;
}