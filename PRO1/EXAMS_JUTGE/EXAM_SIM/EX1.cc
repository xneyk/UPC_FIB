#include <iostream>
using namespace std;

int main() {
   int x, y, z;
   bool exist = false;
   cin >> x >> y >> z;

   if ((x + y)/2.0 == z) exist = true;
   else if ((y + z)/2.0 == x) exist = true;
   else if ((x + z)/2.0 == y) exist = true;

   if (exist) cout << "YES" << endl;
   else cout << "NO" << endl;
}