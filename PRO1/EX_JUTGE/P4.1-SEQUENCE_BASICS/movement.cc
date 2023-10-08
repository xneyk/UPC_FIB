#include <iostream>
using namespace std;

int main() {
   char c;
   int x = 0;
   int y = 0;

   while (cin >> c) {
      if (c == 'n') --y;
      if (c == 's') ++y;
      if (c == 'e') ++x;
      if (c == 'w') --x;
   }
   cout << '(' << x << ", " << y << ')' << endl;
}