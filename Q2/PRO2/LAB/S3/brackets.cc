#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
   char c;
   stack<char> s;
   bool found = false;

   cin >> c;
   int i = 0;
   while (not found and c != '.') {
      if (c == '(' or c == '[') s.push(c);
      else if (s.empty()) found = true;
      else if (c == ')' and s.top() == '(') s.pop();
      else if (c == ']' and s.top() == '[') s.pop();
      else found = true;

      ++i;
      cin >> c;
   }

   not found and s.empty()
      ? cout << "Correcte"
      : cout << "Incorrecte " << i;
   cout << endl;
}