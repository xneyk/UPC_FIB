#include "Estudiant.hh"
#include <vector>

/**
 * PRE: cert
 * POST: els estudiants de v amb nota passen a tenir la seva nota arrodonida a la decima mes propera
*/
void arrodonir_vector(vector<Estudiant>& v) {
   int length = v.size();
   for (int i = 0; i < length; ++i) {
      if (v[i].te_nota()) {
         int rounded = 10*(v[i].consultar_nota() + 0.05);
         v[i].modificar_nota(rounded/10.);
      }
   }
}