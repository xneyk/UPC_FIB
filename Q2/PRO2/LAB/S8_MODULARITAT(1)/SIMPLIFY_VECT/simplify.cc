#include "Estudiant.hh"
#include <vector>

int main() {
   int n;
   cin >> n;
   vector<Estudiant> v(n);
   Estudiant est;
   for (int i = 0; i < n; ++i) {
      est.llegir();
      v[i] = est;
   }
   vector<Estudiant> u;
   u.push_back(v[0]);
   int u_last = 0;
   for (int i = 1; i < n; ++i) {
      if (v[i].consultar_DNI() == u[u_last].consultar_DNI()) {
         double v_score = v[i].te_nota() ? v[i].consultar_nota() : -1;
         double u_score = u[u_last].te_nota() ? u[u_last].consultar_nota() : -1;

         if (v_score > -1 && u_score > -1) {
            u[u_last].modificar_nota(v_score > u_score ? v_score : u_score);
         }
         else if (v_score > -1 && u_score == -1) u[u_last].afegir_nota(v_score);
         // si v_score no te nota no volem ignorar-lo.
      } else {
         u.push_back(v[i]);
         ++u_last;
      }
   }

   for (int i = 0; i <= u_last; ++i) u[i].escriure();
}