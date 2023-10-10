#include <iostream>
using namespace std;

int main() {
   char letter, new_letter;
   int i, a, b, c, d;
   i = a = b = c = d = 0;
   
   cin >> letter;
   new_letter = letter;
   while (a < 2 and b < 2 and c < 2 and d < 2) {
      if (letter == 'a'){
         new_letter = 'a';
         a++;
      }
      else if (letter == 'b'){
         new_letter = 'b';
         b++;
      }
      else if (letter == 'c'){
         new_letter = 'c';
         c++;
      }
      else {
         new_letter = 'd';
         d++;
      }

      ++i;
      cin >> letter;
   }
   cout << new_letter << ' ' << (i - 1) << endl;
}