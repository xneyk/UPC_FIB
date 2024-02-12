//P38877 Reversing a list of words (4)
#include <iostream>
using namespace std;

void print_list(int pos, int& n) {
   string s;
   if (cin >> s) {
      print_list(pos + 1, n);
      if (pos < n/2) cout << s << endl;
   }
   else n = pos;
}

int main() {
   int n = 0;
   print_list(0, n);
}