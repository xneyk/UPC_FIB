//P35537 Increasing numbers
#include <iostream>
using namespace std;

bool is_increasing(int n);

int main() {
   int x;
   while (cin >> x) {
      is_increasing(x) ? cout << "true" : cout << "false";
      cout << endl;
   }
}

bool is_increasing(int n) {
   if (n <= 0) return true;
   else return n%10 >= (n/10)%10 and is_increasing(n/10);
}