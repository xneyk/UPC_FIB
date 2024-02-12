#include <iostream>
#include <vector>
using namespace std;

/**
 * PRE:  v es el vector en el que estem fent la busqueda
 *       l, r son els extrems del subvector on hem de fer la busqueda.
 * POST: 
*/
int rec_search(const vector<int>& v, int l, int r, int res) {
   if (r - l > 1) { // volem parar la recursio si no l'hem trobat i el tamany del subvector < 1
      int mid = (l + r) / 2;
      int d = v[mid] - v[mid + 1];
      if (d == 1 or d == -1) return mid;
      else {
         rec_search(v, l, mid, res);
         rec_search(v, mid, r, res);
      }
   }
}

// Pre: Sigui n el tamany v.size(). Llavors, per a cada i a {0..n-2}, es compleix |v[i]-v[i+1]|<=2.
//      A més, només hi ha un i a {0..n-2} que compleixi |v[i]-v[i+1]|=1.
// Post: La funció retorna el i praticular que compleix |v[i]-v[i+1]|=1.
int positionDistance1(const vector<int> &v) {
   int res = -1;
   int ini_l = 0, ini_r = (v.size() - 1);
   
   rec_search(v, ini_l, ini_r, res);

   return res;
}

int main() {
   int n;
   while (cin >> n) {
      vector<int> v(n);
      for (int i = 0; i < n; ++i) cin >> v[i];
      
      cout << positionDistance1(v) << endl;
   }
}