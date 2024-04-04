#include <iostream>
#include <list>

using namespace std;

int main() {
   string command;
   list<int> l;
   int list_length = 0, balance = 0;
   list<int>::iterator mid_pointer = l.end();

   while (cin >> command) {
      int x;

      if (command == "push_front") {
         cin >> x;
         l.push_front(x);

         ++list_length;
         if (list_length > 1) --balance;
         else {
            mid_pointer = l.begin(); // hi ha un sol element
            balance = 0;
         }
      }
      else if (command == "push_back") {
         cin >> x;
         l.push_back(x);

         ++list_length;
         if (list_length > 1) ++balance;
         else {
            balance = 0;
            mid_pointer = l.begin(); // hi ha un sol element
         }
      }
      else if (command == "pop_front") {
         if (!l.empty()) {
            l.pop_front();

            --list_length;
            if (list_length > 1) ++balance;
            else {
               mid_pointer = l.begin(); // hi ha un sol element
               balance = 0;
            }
         } else {
            cout << "error" << endl;
         }
      }
      else if (command == "pop_back") {
         if (!l.empty()) {
            l.pop_back();

            --list_length;
            if (list_length > 1) --balance;
            else {
               mid_pointer = l.begin(); // hi ha un sol element
               balance = 0;
            }
         } else {
            cout << "error" << endl;
         }
      }
      else if (command == "get_mid_value") {
         if (list_length == 0 || list_length%2 == 0) cout << "error" << endl;
         else cout << *mid_pointer << endl;
      }

      if (balance == 2) {
         ++mid_pointer;
         balance = 0;
      }
      else if (balance == -2) {
         --mid_pointer;
         balance = 0;
      }
   }
}