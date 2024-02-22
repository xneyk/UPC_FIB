#include <iostream>
#include <vector>
using namespace std;

/**
 * PRE: cierto
 * POST: si el resultado es v.size(), x no esta en v; 
 * en caso contrario, indica la posicion de la primera aparicion de x en v
*/
int busqueda_lin(const vector<int> &v, int x) {
   int tam = v.size();
   int i = 0;
   bool b = false;
   while (i < tam and not b) {
      if (v[i] == x) b = true;
      else ++i;
   }
   
   if (b) return i;
   else return tam;
}