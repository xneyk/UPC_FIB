#include <iostream>
using namespace std;

#include "ArbreG.hh"
#include "ArbGIOint.hh"

int main() {
   ArbreGen<int> a;
   llegir_arbre_int(a, 0);
   
   a.buscar(3) ? cout << "true\n" : cout << "false\n";
   
   escriure_arbre_int(a);
   cout << endl;
}
