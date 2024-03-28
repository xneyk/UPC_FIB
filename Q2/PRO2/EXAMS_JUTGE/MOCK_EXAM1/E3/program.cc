#include <iostream>
#include <stack>
#include <sstream>

using namespace std;


int longest_prefix(string word) {
   stack<char> s;
   char c;
   int i = 0, prefix_index = 0;
   istringstream iss_word(word);

   while (iss_word >> c) {
      if (c == '(' || c == '[') s.push(c);
      else if (c == ')') {
         if (!s.empty() && s.top() == '(') s.pop();
         else return prefix_index;
      }
      else if (c == ']') {
         if (!s.empty() && s.top() == '[') s.pop();
         else return prefix_index;
      }
      ++i;
      if (s.empty()) prefix_index = i;
   }

   return prefix_index;
}

int main() {
   string word;

   while(getline(cin, word)) {
      cout << longest_prefix(word) << endl;
   }
}