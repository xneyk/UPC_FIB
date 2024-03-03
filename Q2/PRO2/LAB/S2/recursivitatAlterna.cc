#include <iostream>
#include <vector>
using namespace std;

void altern_rec(int n, int offset) {
   for (int i = 0; i < n-1; ++i) offset *= 2;
   
   if (n <= 0) {
      for (int i = 0; i < offset; ++i) cout << ' ';
      cout << '*' << endl;
   } else {
      int offset = 1;
      if (n%2 == 0) {
         for (int i = 0; i < offset; ++i) cout << ' ';
         altern_rec(n-1, offset*2);
         for (int i = 0; i < offset; ++i) cout << ' ';
         altern_rec(n-1, offset);
      } else {
         for (int i = 0; i < offset; ++i) cout << ' ';
         altern_rec(n-1, offset);
         for (int i = 0; i < offset; ++i) cout << ' ';
         altern_rec(n-1, offset*2);
      }
   }
}

int main () {
   int n;
   while (cin >> n) {
      altern_rec(n, 0);
      cout << "----------" << endl;
   }
}