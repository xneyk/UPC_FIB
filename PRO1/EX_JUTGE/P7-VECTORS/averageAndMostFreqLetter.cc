//X20419 Average length and most frequent letter
#include <iostream>
#include <vector>
using namespace std;

char most_frequent_letter(const string& s) {
   const int LENGTH_ALPHABET = 'z' - 'a' + 1;
   const int ALPHABET_BEGINNING = 'a';
   vector<int> freq_counter(LENGTH_ALPHABET, 0);
   int l = s.size();
   
   for (int i = 0; i < l; ++i) {
      ++freq_counter[s[i] - ALPHABET_BEGINNING];
   }

   //Calc index of the maximum...
   int max_i = 0;
   for (int i = 0; i < LENGTH_ALPHABET; ++i) {
      if (freq_counter[i] > freq_counter[max_i]) max_i = i;
   }

   return char(ALPHABET_BEGINNING + max_i);
}

int main() {
   cout.setf(ios::fixed);
   cout.precision(2);

   int n;
   cin >> n;
   
   vector<string> v(n);
   double average = 0;
   for (int i = 0; i < n; ++i) {
      cin >> v[i];
      average += v[i].size();
   }
   average /= n; // average takes the correct value.
   
   cout << average << endl;
   for (int i = 0; i < n; ++i) {
      if (v[i].size() >= average) {
         cout << v[i] << ": " << most_frequent_letter(v[i]) << endl;
      }
   } 
}