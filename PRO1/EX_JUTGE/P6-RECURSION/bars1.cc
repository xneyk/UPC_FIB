//P62467 Bars (1)
#include <iostream>
using namespace std;

void print_case_n(int n);

int main() {
   int x;
   cin >> x;
   print_case_n(x);
}

void print_case_n(int n) {
   if (n == 1) cout << '*' << endl;
   else {
      print_case_n(n - 1);
      for (int i = 0; i < n; ++i) cout << '*';
      cout << endl;
      print_case_n(n - 1);
   }
}