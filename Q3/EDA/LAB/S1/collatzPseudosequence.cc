#include <iostream>
#include <set>
#include <queue>

int next_n(const int& x, const int& y, int n) {
   if (n%2 == 0) return n/2 + x;
   return 3*n + y;
}

int main() {
   int MAX_ITERATIONS = 100000000;
   int x, y, n;
   while (std::cin >> x >> y >> n) {
      bool cycle_found = false;
      std::set<int> collection;
      
      while (not cycle_found and MAX_ITERATIONS >= 0) {
         cycle_found = not collection.insert(n).second; // not (true iff insertion took place) ==> if not reapeated

         std::cout << MAX_ITERATIONS << ": " << n << std::endl;
         // RECORDAR A QUE ITERACION HE METIDO CADA NUMERO, EN EL MOMENTO EN EL QUE TENGA REPETICION SE CUANTO MIDE EL CICLO.
         if (cycle_found) {
            std::queue<int> cycle;
            cycle.push(n);

            while (cycle.front() != next_n(x, y, n)) {
               n = next_n(x, y, n);
               cycle.push(n);
            }
            std::cout << cycle.size() << std::endl; // we found a cycle so we print its length

            std:: cout << cycle.front() << ' ' << next_n(x, y, n) << std::endl;
         }
         

         n = next_n(x, y, n);
         --MAX_ITERATIONS;
      }

      if (not cycle_found) std::cout << "last: " << n << std::endl; // we haven't found a cycle so we print the last n.
   }
}