//X88601 reverseSubstring
#include <iostream>
#include <string>
using namespace std;

// Pre: 0 <= i <= j < s.size()
// Post: el substring s[i..j] s'ha revessat. La resta de s no ha canviat.
void reverseSubstring(string &s, int i, int j) {
   if (j-i > 2) reverseSubstring(s, i+1, j-1);
   
   char aux = s[i];
   s[i] = s[j];
   s[j] = aux;
}

int main() {
   string s;
   while (cin >> s) {
      int i = 0, j = s.size() - 1;
      reverseSubstring(s, i, j);
      cout << s << endl;
   }
}