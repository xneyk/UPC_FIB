#include <iostream>
using namespace std;

int main() {
   int x, y;

   while (cin >> x >> y) {
      int r = 0;
      cout << "suma dels cubs entre " << x << " i " << y << ": ";

      for (int i = y; i >= x ; --i) {
         r += i*i*i;
      }
      cout << r << endl;
   }
}