//X80577 Bounded growth chains
#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> v;
   int n, max = 0;
   while (cin >> n and n != -1) {
      v.push_back(n);
      if(n > max) max = n; //update max.
   }
   for (int i = 0; i < n; ++i) {
      //... buscar cadena.
   }
}