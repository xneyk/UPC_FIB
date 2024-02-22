// X54177 Suma de secuencias de enteros
#include <iostream>
using namespace std;

int main() {
  int n_sec, x;
  string s; // su unico uso es consumir los datos sobrantes de cada linea.
  cin >> n_sec >> x;

  for (int i = 1; i <= n_sec; ++i) {
    int n, res = 0;
    bool found = false;

    while (not found and cin >> n) {
      if (not(n == x)) res += n;
      else found = true;
    }

    getline(cin, s);
    cout << "La suma de la secuencia " << i << " es " << res << endl;
  }
}