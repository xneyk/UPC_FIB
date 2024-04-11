#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int main() {
   string input;
   while (getline(cin, input)) {
      istringstream iss_input (input);

      char c;
      int changes_needed = 0;
      stack<char> s;
      while (iss_input >> c) {
         if (c == '(') s.push(c);
         else if (c == '[') s.push(c);
         if (c == ')') {
            if (s.empty()) {
               ++changes_needed;
               s.push('(');
            }
            else {
               if (s.top() != '(') ++changes_needed;
               s.pop();
            }
         }
         if (c == ']') {
            if (s.empty()) {
               ++changes_needed;
               s.push('[');
            }
            else {
               if (s.top() != '[') ++changes_needed;
               s.pop();
            }
         }
      }
      if (!s.empty()) changes_needed = s.size() / 2;
      cout << changes_needed << endl;
   }
}