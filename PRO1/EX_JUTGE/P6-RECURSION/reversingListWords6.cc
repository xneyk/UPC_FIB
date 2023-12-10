//P38877 Reversing a list of words (4)
#include <iostream>
using namespace std;

void print_list(int& n, int& n_copy) {
   string s;
   if (cin >> s) {
      ++n;
      n_copy = n;
      print_list(n, n_copy);
      if (n < n_copy/2) cout << s << endl;
   }
   --n;
}

int main() {
   int n = 0;
   int n_copy = 0;
   print_list(n, n_copy);
}