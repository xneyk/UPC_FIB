#include <iostream>
using namespace std;

int main() {
   int a = 0; // contador de a's
   char c;

   cin >> c;
   while (c != '.') {
      if(c == 'a') ++a;
      cin >> c;
   }
   cout << a << endl;
}