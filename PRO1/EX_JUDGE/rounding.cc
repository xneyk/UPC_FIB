#include <iostream>
using namespace std;

int main(){
   double a;
   int r;
   cin >> a;
   
   if(a - int(a) != 0){
      // rounding //
      if(a - int(a) >= 0.5){
         r = int(a) + 1;
      } else {
         r =  int(a);
      }

      // floor of x //
      cout << int(a) << ' ';
      // ceiling of x //
      cout << int(a) + 1 << ' ';
      // rounded of x //
      cout << r << endl;

   } else {
      r = a;
      cout << r << ' ' << r << ' ' << r << endl;
   }   
}