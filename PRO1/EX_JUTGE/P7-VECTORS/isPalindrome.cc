//P50497 Is it a palindrome?
#include <iostream>
#include <vector>
using namespace std;

bool is_palindrome(const string& s);

int main() {
   string str;
   while (cin >> str) cout << is_palindrome(str) << endl;
}

bool is_palindrome(const string& s) {
   int l = s.size();
   int r = l-1;
   for (int i = 0; i < l/2; ++i) {
      if (s[i] != s[r]) return false;
      --r;
   }
   return true;
}