//P52926 Reversing a list of words (2)
#include <iostream>
using namespace std;

void print_reversed() {
   string s;
   cin >> s;
   if (s != "end") {
      print_reversed();
      cout << s << endl;
   }
}

int main() {
   print_reversed();
}