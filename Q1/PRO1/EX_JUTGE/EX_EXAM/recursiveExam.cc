#include <iostream>
using namespace std;

void rec(int x) {
   if (x == 1) cout << '*' << endl;
   else  {
      rec(x - 1);
      for (int i = 0; i < x; ++i) {
         for (int j = 0; j < x; ++j) cout << '*';
         cout << endl;
      }
      rec(x - 1);
   }
}

int main() {
   int n;
   while (cin >> n) {
      rec(n);
      cout << endl;
   }

}