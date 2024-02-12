//P38877 Reversing a list of words (4)
#include <iostream>
using namespace std;

void print_list(int& n) {
   string s;   
   if(cin >> s) {
      print_list(n);
      if (n >= 0) cout << s << endl;
   }
   --n;
}

int main() {
   int n;
   cin >> n;
   print_list(n);
}