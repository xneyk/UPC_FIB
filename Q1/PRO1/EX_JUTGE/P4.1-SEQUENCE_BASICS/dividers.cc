#include <iostream>
using namespace std;

int main() {
   int n;

   while (cin >> n) {
      cout << "divisors de " << n << ':';
      int i = 1;
      int last_div = i;
      while (i*i <= n){
         if (n % i == 0) {
            cout << ' ' << i;
            last_div = i;
         }
         ++i;
      }
      
      while (last_div*last_div > 0){
         if ((n % last_div == 0) and (n / last_div != last_div)) cout << ' ' << (n / last_div);
         --last_div;
      }
      cout << endl;
   }
}