#include <iostream>
using namespace std;

int main() {
   int n, r;
   cin >> n;

   r = 0;

   for (int i = 0; i<=n; ++i){
      r = r + (i * i);
   }

   cout << r << endl;
}