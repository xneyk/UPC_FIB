#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct bracket_index {
   char bracket;
   int index;
};

int main() {
   string s;

   while (cin >> s) {
      queue<bracket_index> waiting_exit;
      stack<bracket_index> opened_brackets;
      int n = s.size();

      for (int i = 0, b_index = 1; i < n; ++i) {
         bracket_index elem;
         elem.bracket = s[i];
         elem.index = b_index;
         if (s[i] == '(') {
            opened_brackets.push(elem);
            ++b_index;
         } else { // s[i] == ')'
            elem.index = opened_brackets.top().index;
            opened_brackets.pop();
         }
         
         waiting_exit.push(elem);
      }

      while (not waiting_exit.empty()) {
         cout << waiting_exit.front().bracket << waiting_exit.front().index;
         waiting_exit.pop();
      }
      cout << endl;
   }
}