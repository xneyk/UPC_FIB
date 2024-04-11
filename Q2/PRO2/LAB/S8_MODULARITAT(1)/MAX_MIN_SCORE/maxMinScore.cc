#include "Estudiant.hh"
#include <vector>

/**
 * PRE: v no conte repeticions de dni
 * POST: si existeix a v algun estudiant amb nota, la primera component del
 * resultat es la posicio de l'estudiant de nota maxima de v i la segona
 * component es la posicio de l'estudiant de nota minima de v (si hi ha empats,
 * s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no hi ha cap
 * estudiant amb nota, totes dues components valen -1.
*/
pair<int,int>  max_min_vest(const vector<Estudiant>& v) {
   pair<int,int> res(-1,-1);
   double max = -1, min = 11;
   const int V_LENGHT = v.size();

   for (int i = 0; i < V_LENGHT; ++i) {
      if (v[i].te_nota()) {
         double est_score = v[i].consultar_nota();
         int est_dni = v[i].consultar_DNI();

         if (est_score > max) {
            max = est_score;
            res.first = i;
         }
         else if (est_score == max && est_dni < v[res.first].consultar_DNI()) {
            max = est_score;
            res.first = i;
         }
         if (est_score < min) {
            min = est_score;
            res.second = i;
         }
         else if (est_score == min && est_dni < v[res.second].consultar_DNI()) {
            min = est_score;
            res.second = i;
         }
      }
   }

   return res;
}
