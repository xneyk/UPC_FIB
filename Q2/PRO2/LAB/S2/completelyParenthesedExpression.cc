#include <iostream>
using namespace std;

int calc() {
   char x, op;
   cin >> x;

   if ('0' <= x and x <= '9') return x - '0';
   else {
      int a = calc();
      cin >> op; // llegim operador
      int b = calc();
      cin >> x; // consumim parentesis ')'
      
      if (op == '+') return a + b; 
      else if (op == '-') return a - b;
      else return a*b;
   }

}

int main() {
   cout << calc() << endl;
}