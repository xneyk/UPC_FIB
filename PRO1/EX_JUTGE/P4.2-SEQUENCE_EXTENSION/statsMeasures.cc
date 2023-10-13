#include <iostream>
using namespace std;

int main() {
   cout.setf(ios::fixed);
	cout.precision(4);

   int n;
   cin >> n;

   for (int i = 0; i < n; ++i) {
      int m;
      double x, min, max, average;
      cin >> m >> x; // Tratamos el primer elemento de la secuencia. (POS.0)
      min = max = average = x;

      for (int j = 1; j < m; ++j) { // Empezamos el tratamiento a partartir del segundo elemento (POS.1)
         cin >> x;
         if (x > max) max = x;
         else if (x < min) min = x;
         average += x;
         if(j == (m - 1)) average /= m;
      }
      cout << min << ' ' << max << ' ' << average << endl;
   }
}