#include <iostream>
using namespace std;

void print_line(char c, string s, bool b) {
   cout << s << "('" << c << "') = ";
   if (b) cout << "true" << endl;
   else cout << "false" << endl;
}

bool uppercase(char c) {
   return 'A' <= c and c <= 'Z';
}

bool lowercase(char c) {
   return 'a' <= c and c <= 'z';
}

bool digit(char c) {
   return '0' <= c and c <= '9';
}

bool vowel(char c) {
   if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') return true;
   if (c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U') return true;
   else return false;
}

int main() {
   char c;
   while (cin >> c) {
      bool low = lowercase(c);
      bool up = uppercase(c);

      print_line(c, "letter", up or low);
      print_line(c, "vowel", vowel(c));
      print_line(c, "consonant", not vowel(c) and (up or low));
      print_line(c, "uppercase", up);
      print_line(c, "lowercase", low);
      print_line(c, "digit", digit(c));
   }
}