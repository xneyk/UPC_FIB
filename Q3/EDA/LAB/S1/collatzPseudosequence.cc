#include <iostream>
#include <map>

int next_n(const int& x, const int& y, int n) {
   if (n%2 == 0) return n/2 + x;
   return 3*n + y;
}

int main() {
   int MAX_OCURRENCE = 100000000;
   int x, y, n;
   while (std::cin >> x >> y >> n) {
      bool cycle_found = false;
      std::map<int,int> collection;
      int i = 0;
      while (not cycle_found and n <= MAX_OCURRENCE) {
         if (collection.find(n) == collection.end()) {
            collection[n] = i; // n no habia salido aun
            n = next_n(x, y, n);
            ++i;
         }
         else cycle_found = true;
      }
      if (cycle_found) {
         std::cout << i - collection[n] << std::endl;
      } else {
         std::cout << n << std::endl;
      }
   }
}