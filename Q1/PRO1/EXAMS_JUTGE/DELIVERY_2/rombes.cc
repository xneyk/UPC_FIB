#include <iostream>
using namespace std;

int main() {
   int numspaces, numrombes;

   while (cin >> numspaces >> numrombes) {
      for (int k = 1; k <= numrombes; ++k){
         for (int i = 0; i <= numspaces; ++i) {
            bool finished = false;
            int j = 0;

            while (not finished) {
               if (j == numspaces - i){
                  cout << '*';
               } else {
                  cout << ' ';
               }
               if(j == (numspaces - 1) + i) {
                  cout << '*' << endl;
                  finished = true;
               }
               ++j;
            }
         }
         for (int i = (numspaces - 1); i > 0; --i) {
            bool finished = false;
            int j = 0;

            while (not finished) {
               if (j == numspaces - i){
                  cout << '*';
               } else {
                  cout << ' ';
               }
               if(j == (numspaces - 1) + i) {
                  cout << '*' << endl;
                  finished = true;
               }
               ++j;
            }
         }
      }
      for (int l = 1; l <= numspaces; ++l) cout << ' ';
      cout << '*' << endl << endl;
   }
}