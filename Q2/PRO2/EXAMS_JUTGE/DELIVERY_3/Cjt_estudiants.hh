#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include <vector>
#include <iostream>
#include "Estudiant.hh"

using namespace std;

class Cjt_estudiants {

private:

  // Representa un conjunt d'estudiants ordenat per DNI.  
  
  vector<Estudiant> vest; // estudiants del conjunt

  int nest; // nombre d'estudiants del conjunt 

  static const int MAX_NEST = 1500000; // nombre maxim d'elements del conjunt

  vector<int> intervals; // nombre d'estudiants del conjunt a cada interval:

  /* 
     Invariant de la representaci�: 
     - vest[0..nest-1] est� ordenat creixentment pel dni dels estudiants i no cont� estudiants repetits
     - 0 <= nest <= vest.size() = MAX_NEST
     - intervals.size() = 10
     - per a tot i entre 0 i 8, intervals[i] �s el nombre d'estudiants de vest[0..nest-1] que satisfan i <= nota < i + 1   
     - intervals[9] �s el nombre d'estudiants de vest[0..nest-1] que satisfan 9 <= nota <= 10
  */
 
  void ordenar();
  /* Pre: cert */
  /* Post: el elements del par�metre impl�cit passen a estar ordenats
     creixentment per DNI. */
     
  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);
  /* Pre: els elements de vest estan ordenats creixentment per DNI,
     0 <= left, right < vest.size(), right >= left + 1 */
  /* Post: si x hi �s vest[left..right], el resultat �s la posici� que
     hi ocupa, si no, �s la posici� que hauria d'ocupar */

public:

  //Constructores

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: crea un conjunt d'estudiants buit */

  //Modificadores

  void afegir_estudiant(const Estudiant &est, bool &b);
  /* Pre: el par�metre impl�cit no est� ple */
  /* Post: b = indica si el p.i. original cont� un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al par�metre impl�cit */

  void esborrar_estudiant(int dni, bool &b);
  /* Pre: cert */
  /* Post: b indica si el par�metre impl�cit original tenia un estudiant 
     amb el dni dni; si b, aquest estudiant ha quedat eliminat
     del par�metre impl�cit */

   
  void incrementar_interval(double x);
  /* Pre: x �s una nota v�lida */
  /* Post: al par�metre impl�cit, s'ha incrementat en una unitat el valor de
     la posici� d'"intervals" corresponent a x */

  void decrementar_interval(double x);
  /* Pre: x �s una nota v�lida */
  /* Post: al par�metre impl�cit, s'ha decrementat en una unitat el valor de
     la posici� d'"intervals" corresponent a x */

  //Consultores
	
  int mida() const;
  /* Pre: cert */
  /* Post: El resultat �s el nombre d'estudiants del par�metre impl�cit */

  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat �s el nombre maxim d'estudiants que pot arribar
     a tenir el par�metre impl�cit */

  int nombre_est_interval(int i) const;
  /* Pre: 0 <= i <= 9 */
  /* Post: el resultat �s el nombre d'estudiants del par�metre impl�cit amb
     nota a l'interval i */

  // Lectura i escriptura
	
  void llegir();
  /* Pre: estan preparats al canal est�ndar d'entrada un enter  (entre 0 i la
     mida maxima permesa per a la classe), que representa el nombre d'elements 
     que llegirem, i les dades de tal nombre d'estudiants diferents */
  /* Post: el par�metre impl�cit cont� el conjunt d'estudiants llegits
     del canal est�ndar d'entrada */

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal est�ndar de sortida els estudiants del
     par�metre impl�cit en ordre ascendent per DNI */
};

#endif

