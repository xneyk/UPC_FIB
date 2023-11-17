#include <iostream>
using namespace std;

bool is_valid_date(int d, int m, int y);
bool is_leap_year(int year);

int main() {
   int d, m, y;
   while (cin >> d >> m >> y) cout << (is_valid_date(d, m, y) ? "true" : "false") << endl;
}

bool is_leap_year(int year) {
   if (year % 4 == 0 and year % 100 != 0) return true;
   if (year % 100 == 0 and year / 100 % 4 == 0) return true;
   
   return false;
}

//Pre: Year between 1800 and 9999
bool is_valid_date(int d, int m, int y) {
   int m_days = 28;

   if (m == 2) {
      if (is_leap_year(y)) m_days= 29;
   } else {
      if (((m % 2 > 0) and (m <= 7)) or ((m % 2 == 0) and (m >= 8))) {
         // Messos que tenen 31 dies 1,3,5,7,8,10,12
         m_days = 31;
      } else {
         // La resta de messos tenen 30 dies
         m_days = 30;
      }
   }

   if ((1 <= d) and (d <= m_days) and (1 <= m) and (m <= 12)) return true;
   return false;
}