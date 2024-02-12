#include <iostream>
using namespace std;

int main(){
   char c;
   int up_low_offset = 'a' - 'A'; //32
   
   cin >> c;

   if(c>='a'&&c<='z'){
      // is lowercase
      cout << (char(c - up_low_offset)) << endl;
   } else {
      // is uppercase
      cout << (char(c + up_low_offset)) << endl;
   }
}