#include <iostream>
using namespace std;

int main() {
   // aaa aab aba abb baa bab bba bbb son las 8 posibles convinaciones de a y b con 3 caracteres.
   bool aaa = false;
   bool aab = false;
   bool aba = false;
   bool abb = false;
   bool baa = false;
   bool bab = false;
   bool bba = false;
   bool bbb = false;

   bool found = false;
   char c1, c2, c3;
   int i = 0;

   cin >> c1 >> c2 >> c3;
   while (not found) {
      if (c1 == 'a') {
         if (c2 == 'a') {
            if (c3 == 'a') {
               if (not aaa) aaa = true;
               else {
                  found = true;
                  cout << "aaa ";
               }
            } else {
               if (not aab) aab = true;
               else {
                  found = true;
                  cout << "aab ";
               }
            }
         }
         if (c2 == 'b') {
            if (c3 == 'a') {
               if (not aba) aba = true;
               else {
                  found = true;
                  cout << "aba ";
               }
            } else {
               if (not abb) abb = true;
               else {
                  found = true;
                  cout << "abb ";
               }
            }
         }
      } else {
         if (c2 == 'a') {
            if (c3 == 'a') {
               if (not baa) baa = true;
               else {
                  found = true;
                  cout << "baa ";
               }
            } else {
               if (not bab) bab = true;
               else {
                  found = true;
                  cout << "bab ";
               }
            }
         }
         if (c2 == 'b') {
            if (c3 == 'a') {
               if (not bba) bba = true;
               else {
                  found = true;
                  cout << "bba ";
               }
            } else {
               if (not bbb) bbb = true;
               else {
                  found = true;
                  cout << "bbb ";
               }
            }
         }
      }
      ++i;
      c1 = c2;
      c2 = c3;
      cin >> c3;
   }

   cout << (i - 1) << endl;
}