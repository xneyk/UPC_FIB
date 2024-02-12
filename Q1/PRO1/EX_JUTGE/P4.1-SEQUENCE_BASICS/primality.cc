#include <iostream>
using namespace std;

int main() {
   int n, m;
   cin >> n;
   
   for (int i = 0; i < n; ++i) {
      bool is_prime = true; // Partiremos de la hipostesi de que es un numero primo
      cin >> m;
      if (m < 2) is_prime = false;
      
      int j = 2;
      while ((j*j <= m) and is_prime){
         if (m % j == 0) is_prime = false;
         ++j;
      }
      if (is_prime) cout << m << " is prime" << endl;
      else cout << m << " is not prime" << endl;
   }
}