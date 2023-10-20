#include <iostream>
using namespace std;

int main() {
   bool exist_hello = false;
   char letter;
   char last1, last2, last3, last4;
   last1 = last2 = last3 = last4 = ' ';

   cin >> letter;
   while (letter != '.') {
      string word = "";
      
      word += last4;
      word += last3;
      word += last2;
      word += last1;
      word += letter;
   
      if(word == "hello") exist_hello = true;
      
      last4 = last3;
      last3 = last2;
      last2 = last1;
      last1 = letter;
      cin >> letter;
   }

   if (exist_hello) cout << "hello" << endl;
   else cout << "bye" << endl;
}