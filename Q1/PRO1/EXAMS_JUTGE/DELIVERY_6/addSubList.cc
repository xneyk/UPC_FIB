#include <iostream>
#include <vector>

using namespace std;

/**
 * PRE: v un vector d'enters
 * POST: v inicialitzat amb la secuencia d'n valors enters.
*/
void ini_vector (vector<int>& v) {
   int lenght = v.size();
   int elem; // element del vector
   for (int i = 0; i < lenght; ++i) {
      cin >> elem;
      v[i] = elem;
   }
}

int main() {
   int n;
   cin >> n;
   vector<int> v (n);
   ini_vector(v); // Inicialitza el vector.

   string operands;
   while (cin >> operands) {
      int result = 0;
      for (int i = 0; i < n; ++i) {
         if (operands[i] == '+') result += v[i];
         else result -= v[i];
      }
      cout << result << endl;
   }
}