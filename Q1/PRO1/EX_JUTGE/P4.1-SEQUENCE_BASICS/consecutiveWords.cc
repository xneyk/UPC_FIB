#include <iostream>
using namespace std;

int main() {
   string sequence_word, prev_word, word;
   int counter = 1;
   int longer_counter = 1;

   cin >> sequence_word;
   prev_word = sequence_word;
   while (cin >> word) {
      if (word == sequence_word and word == prev_word) ++counter;
      else counter = 1;

      if (longer_counter < counter) longer_counter = counter;
      prev_word = word;
   }
   cout << longer_counter << endl;
}