#include <iostream>
using namespace std;

int main(){
   int a1, b1, a2, b2;
   int r1, r2;
   cin >> a1 >> b1 >> a2 >> b2;

   // Assumim que a1 < b1 i a2 < b2

   if((a1 >= a2 and b1 <= b2) or (a2 >= a1 and b2 <= b1)){
      if(not (a1 == a2 and b1 == b2)){
         if((a1 >= a2 and b1 <= b2)){
            cout << "1 , ";
         } else {
            cout << "2 , ";
         }
      } else {
         cout << "= , ";
      }
   } else {
      cout << "? , ";
   }

   if(not ((a1 > b2 or b1 < a1) or (a2 > b1 or b2 < a2))) {
      if(a1 >= a2 and a1 <= b2){
         r1 = a1;
         if(b1 >= a2 and b1 <= b2){
            r2 = b1;
         } else {
            r2 = b2;
         }
         cout << '[' <<  r1 << ',' << r2 << ']' << endl;
      } else {
         if(a2 >= a1 and a2 <= b1){
            r1 = a2;
            if(b2 >= a1 and b2 <= b1){
               r2 = b2;
            } else {
               r2 = b1;
            }
            cout << '[' <<  r1 << ',' << r2 << ']' << endl;
         }
      }

   } else {
      cout << "[]" << endl;
   }
}