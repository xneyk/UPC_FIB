//X54177 Suma de secuencias de enteros
#include <iostream>
using namespace std;

/**
 * PRE: En la secuencia entrada siempre se encontrara x
 * POST: retorna la suma de todos los numeros anteriores a la primera aparicion de x.
*/
int sum_until_x(int x) {
   bool found = false;
   int n, res = 0;
   string s; //su unico uso es consumir los datos sobrantes de cada linea.

   while (not found and cin >> n) {
      if (not (n == x)) res += n;
      else found = true;
   }

   getline(cin,s);
   return res;
}

int main() {
   int n, x;
   cin >> n >> x;

   for (int i = 1; i <= n; ++i) {
      int sum = sum_until_x(x);
      cout << "La suma de la secuencia " << i << " es " << sum << endl;
   }
}
