//P26041 Reversing a list of words (1)
#include <iostream>
using namespace std;

void print_reversed() {
   string s;
   if (cin >> s) {
      print_reversed();
      cout << s << endl;
   }
}

int main() {
   print_reversed();
}