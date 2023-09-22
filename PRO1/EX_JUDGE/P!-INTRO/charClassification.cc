#include <iostream>
using namespace std;

int main(){
   char c;
   cin >> c;

   if( c >= 'a' && c <= 'z'){
      // is lowercase
      cout << "lowercase" << endl;

      if(c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u'){
         cout << "vowel" << endl;
      } else {
         cout << "consonant" << endl;
      }

   } else {
      // is uppercase
      cout << "uppercase" << endl;

      if(c == 'A' || c == 'E' || c =='I' || c == 'O' || c == 'U'){
         cout << "vowel" << endl;
      } else {
         cout << "consonant" << endl;
      }
   }
}