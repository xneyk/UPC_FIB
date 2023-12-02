#include <iostream>
using namespace std;

void info_sequence(int& sum, int& last);

int main() {
   int ref_sum = 0, ref_last = 0;
   int sum = 0, last = 0;
   int similar_sequences = 1;

   int input;
   while (cin >> input and input != 0) { // Lectura primera sequencia per a tenirla de referencia
      ref_last = input;
      info_sequence(ref_sum, ref_last);
   }
   while (cin >> input and input != 0) { // Lectra de la resta de sequencies.
      while (input != 0) {
         last = input;
         info_sequence(sum, last);
         cin >> input;
      }
      if (sum == ref_sum and last == ref_last) ++similar_sequences;
      sum = last = 0;

   }
   
   cout << similar_sequences << endl;
}

void info_sequence(int& sum, int& last) {
   sum += last;
}