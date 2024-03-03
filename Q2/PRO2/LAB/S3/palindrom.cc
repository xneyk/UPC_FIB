//X96935 Palíndroms amb piles
#include <iostream>
#include <stack>
using namespace std;

bool palindrom(int n) {
   stack<int> s;
   int elem;
   for (int i = 0; i < n/2; ++i) {
      cin >> elem;
      s.push(elem);
   }

   if (n%2 != 0) cin >> elem; //Consumimos el elemento central de la secuencia si n impar.

   for (int i = 0; i < n/2; ++i) {
      cin >> elem;
      if (elem != s.top()) return false;
      s.pop();
   }

   return true;
}

int main() {
   int n;
   cin >> n;

   palindrom(n) ? cout << "SI" : cout << "NO";
   cout << endl;
}