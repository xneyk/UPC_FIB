#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void print_stack(const vector<stack<string>>& l) {
   int category;
   cin >> category; // which category they want to print

   stack<string> books(l[category - 1]);
   cout << "Pila de la categoria " << category << endl;
   while (not books.empty()) {
      cout << books.top() << endl;
      books.pop();
   }
   cout << endl;
}

void remove_books(vector<stack<string>>& l) {
   int category, amount;
   cin >> amount >> category;
   for (int i = 0; i < amount; ++i) l[category - 1].pop();
}

void add_book(vector<stack<string>>& l) {
   int category;
   string book;
   cin >> book >> category;
   l[category - 1].push(book);
}

int main() {
   int n, instruction;
   cin >> n;
   vector<stack<string>> library(n);

   while (cin >> instruction and instruction != -4) {
      if (instruction == -3) print_stack(library);
      else if (instruction == -2) remove_books(library);
      else add_book(library);
   }
}