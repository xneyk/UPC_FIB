#include <iostream>
using namespace std;

bool is_leap_year(int year);

int main() {
   int a;
   while (cin >> a) cout << (is_leap_year(a) ? "true" : "false") << endl;
   return 0;
}

bool is_leap_year(int year) {
   if (year % 4 == 0 and year % 100 != 0) return true;
   if (year % 100 == 0 and year / 100 % 4 == 0) return true;
   
   return false;
}