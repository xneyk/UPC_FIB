#include <iostream>
using namespace std;

int main() {
   char letter;
   int i, a, b, c, d;
   i = a = b = c = d = 0;
   
   while (a < 2 and b < 2 and c < 2 and d < 2) {
      cin >> letter;
      if (letter == 'a') ++a;
      else if (letter == 'b') b++;
      else if (letter == 'c') c++;
      else d++;
      
      ++i;
   }
   cout << letter << ' ' << (i - 1) << endl;
}