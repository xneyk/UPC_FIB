//P20006 Prefixed expression (2)
#include <iostream>
using namespace std;

int calc() {
   char input;
   
   cin >> input;
   if (input == '+') return calc() + calc();
   else if (input == '-') return calc() - calc();
   else if (input == '*') return calc() * calc();

   else return int(input) - '0'; // '0'<=input<='9'
}

int main () {
   cout << calc() << endl;
}