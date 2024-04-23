// edgar.aguade@estudiantat.upc.edu L43
// alejandro.madrigal@estudiantat.upc.edu L43

#include "Cjt_estudiants.hh"
#include "PRO2Excepcio.hh"

const char *E1 = "El conjunt és plé!";
const char *E2 = "Nota no vàlida";

void Cjt_estudiants::incrementar_interval(double x) {
   if (x < 0 or 10 < x) throw PRO2Excepcio(E2);
   int nota_interv = x; // si la nota estava entre x.0 i x.9, nota_interv val x (que es l'index a l'interval)
   if (nota_interv >= 9) nota_interv = 9;
   
   ++intervals[nota_interv];
}

void Cjt_estudiants::decrementar_interval(double x) {
   if (x < 0 or 10 < x) throw PRO2Excepcio(E2);
   int nota_interv = x; // si la nota estava entre x.0 i x.9, nota_interv val x (que es l'index a l'interval)
   if (nota_interv >= 9) nota_interv = 9;
   
   --intervals[nota_interv];
}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &b) {
   if (nest >= MAX_NEST) throw PRO2Excepcio(E1);

   int i = cerca_dicot(vest, 0, nest - 1, est.consultar_DNI());
   // vest[i].dni == est.dni ==> est ja hi és
   // sino, hem d'insertar est a la posició.

   b = i < nest and vest[i].consultar_DNI() == est.consultar_DNI();
   // per a trobar l'estudiant que busquem la posició ha de caure dins el rang vàlid de valors
   // i, per altra banda, el dni de l'estudiant que busquem coincidirà amb el de l'estudiant en
   // dita posició.

   if (!b) {
      for (int j = nest; j > i; --j) {
         vest[j] = vest[j-1];
      }
      // vest[i+1] = vest[i] i per tant podem sobre escriure vest[i] amb
      // el valor d'est.
      vest[i] = est;
      ++nest; // Ara hi ha un element més al vector
      
      if (est.te_nota()) { // Si no te nota no l'afegim a cap interval.
         incrementar_interval(est.consultar_nota());
      }
   }

}

void Cjt_estudiants::esborrar_estudiant(int dni, bool &b) {
   int i = cerca_dicot(vest, 0, nest-1, dni);
   // vest[i].dni == est.dni ==> est ja hi és
   // sino, no hi es, per tant, no hem de fer res.

   b = i < nest and vest[i].consultar_DNI() == dni;
   // per a trobar l'estudiant que busquem la posició ha de caure dins el rang vàlid de valors
   // i, per altra banda, el dni de l'estudiant que busquem coincidirà amb el de l'estudiant en
   // dita posició.

   if (b) {
      if (vest[i].te_nota()) { // Si no te nota no hi es a cap interval.
         decrementar_interval(vest[i].consultar_nota());
      }
      for (int j = i; j < nest; ++j) {
         vest[j] = vest[j+1];
      }
      --nest;
   }
}
