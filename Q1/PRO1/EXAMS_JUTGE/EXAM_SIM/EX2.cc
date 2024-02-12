#include <iostream>
using namespace std;

int main() {
   int n;
   
   while (cin >> n) {
      //Llegirem el numero de dreta a esquerra, doncs els pics seran els mateixos.
      int a, b, c;
      int peak_couter = 0;

      a = (n / 100) % 10;
      b = (n / 10) % 10;
      c = n % 10;
      while (n >= 100) { // 100 es l'enter mes petit amb tres xifres
         if (a < b and b > c) ++peak_couter;
         n /= 10;
         c = b;
         b = a;
         a = (n / 100) % 10;
      }
      cout << peak_couter << endl;
   }

}