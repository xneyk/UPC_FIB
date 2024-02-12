#include <iostream>
using namespace std;

int main() {
   int x, n, c = 0;
   
   cin >> x;

   while (cin >> n) {
      if ((n % x) == 0) ++c; 
   }
   cout << c << endl;
}