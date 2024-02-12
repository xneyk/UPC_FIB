#include <iostream>
using namespace std;

int main() {
   int i, n;
   cin >> i;

   cin >> n;
   cout << "At the position " << i << " there is a(n) "; 
   while (n != -1) {
      --i;
      if(i == 0) cout << n << '.' << endl;
      cin >> n;
   }
}