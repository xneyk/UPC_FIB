#include <iostream>
using namespace std;

int main() {
   int y;
   cin >> y;
   
   if((y % 4 == 0 and y % 100 != 0) or (y % 100 == 0 and y / 100 % 4 == 0)){
      cout << "YES" << endl;
   } else {
      cout << "NO" << endl;
   }
}