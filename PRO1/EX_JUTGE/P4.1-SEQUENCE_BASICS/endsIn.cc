#include <iostream>
using namespace std;

int main() {
   int n;
   int i = 0;
   cin >> n;
   int endsIn = n % 1000;

   cout << "nombres que acaben igual que " << n << ":" << endl;
   while (cin >> n) {
      if ((n % 1000) == endsIn) {
         cout << n << endl;
         ++i;
      }
   }
   cout << "total: " << i << endl;
}