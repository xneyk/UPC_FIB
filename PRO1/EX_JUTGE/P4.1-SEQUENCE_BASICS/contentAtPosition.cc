#include <iostream>
using namespace std;

int main() {
   int i, j, n;
   int r = -1;
   /**
    * Como la entrada siempre serán numeros positivos, el único modo
    * de que r = -1 es que no se haya encontrado la posición.
   */
   cin >> i;
   j = i;
   while (cin >> n) {
      --i;
      if(i == 0) r = n;
   }
   if (r == -1) cout << "Incorrect position." << endl;
   else cout << "At the position " << j << " there is a(n) " << r << '.' << endl;
}