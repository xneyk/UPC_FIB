#include <iostream>
using namespace std;

#include "ArbNIOint.hh"
#include "ArbreN.hh"

int main() {
   ArbreNari<int> a = ArbreNari<int>(3);
   ArbreNari<int> b = ArbreNari<int>(3);

   llegir_arbre_int(a, 0);
   escriure_arbre_int(a);
   cout << endl;

   a.arbsuma(b);

   escriure_arbre_int(b);
   cout << endl;
}