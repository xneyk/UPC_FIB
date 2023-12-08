//P38877 Reversing a list of words (4)
#include <iostream>
using namespace std;

void print_list(int& n) {
   ++n;
   string s;
   if (cin >> s) {
      print_list(n);
      if (0 <= n) cout << s << endl;
   }
   n -= 2;
}

int main() {
   int n = 0;
   print_list(n);
}