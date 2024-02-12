#include <iostream>
using namespace std;

int main() {
   bool has_beginning = false;
   int counter = 0;
   string word;
   
   while (cin >> word and word != "end") {
      if (word == "beginning") has_beginning = true;
      if (has_beginning and word != "beginning") ++counter;
   }
   if (has_beginning and word == "end") cout << counter << endl;
   else cout << "wrong sequence" << endl;
}