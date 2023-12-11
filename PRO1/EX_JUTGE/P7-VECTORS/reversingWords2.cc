//P99133 Reversing words (2)
#include <iostream>
#include <vector>
using namespace std;

void print_reversed(int& n) {
   string s;
   if (n > 0) {
      --n;
      cin >> s;
      print_reversed(n);
      for(int i = s.size() - 1; i >= 0; --i) cout << s[i];
      cout << endl;
   }
}

int main() {
   int n;
   cin >> n;
   print_reversed(n);
}