#include <iostream>
#include <vector>

using namespace std;

/**
 * PRE: c1,c2,c3 are pairwise different characters.
 * POST: returns the number of triples (i1,i2,i3) such that 0<=i1<i2<i3<s.size() and
 * s[i1]=c1, s[i2]=c2, s[i3]=c3.
*/
int numberSubsequences(const string &s, char c1, char c2, char c3);
/**
 * PRE: 
 * POST: returns the number of triples (i1,i2,i3) such that 0<=i1<i2<i3<s.size() and
 * either s[i1]=':', s[i2]='-', s[i3]=')' or s[i1]='(', s[i2]='-', s[i3]=':'.
*/
int numberHappySubsequences(const string &s);
/**
 * PRE:
 * POST: returns the number of triples (i1,i2,i3) such that 0<=i1<i2<i3<s.size() and
 * either s[i1]=':', s[i2]='-', s[i3]='(' or s[i1]=')', s[i2]='-', s[i3]=':'.
*/
int numberSadSubsequences(const string &s);

int main() {
   string sequence;
   while (cin >> sequence) {
      cout << numberHappySubsequences(sequence) << ' ';
      cout << numberSadSubsequences(sequence) << endl;
   }
}

int numberSubsequences(const string &s, char c1, char c2, char c3) {
   int result = 0;
   int posibilities = 0;
   int c1_counter = 0;

   int lenght = s.size();
   for (int i = 0; i < lenght; ++i) {
      if(s[i] == c1) ++c1_counter;
      else if(s[i] == c2) posibilities += c1_counter;
      else if(s[i] == c3) result += posibilities;
   }
   return result;
}

int numberHappySubsequences(const string &s) {
   return numberSubsequences(s, '(', '-', ':') + numberSubsequences(s, ':', '-', ')');
}

int numberSadSubsequences(const string &s) {
   return numberSubsequences(s, ')', '-', ':') + numberSubsequences(s, ':', '-', '(');
}