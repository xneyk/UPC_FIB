#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l) {
   list<ParInt>::iterator it = l.end();
   ParInt x;
   while (x.llegir()) {
      l.insert(it, x); 
      /**
       * siempre esta apuntando a l.end(), .insert() no modifica a donde apunta el puntero
       * es por eso que en cada iteracion inserta al final.
      */
   }
}

ostream &operator<<(ostream &os, const ParInt &p) {
   os << p.primer() << ' ' << p.segon();
   return os;
}

void EscriureLlistaParInt(const list<ParInt>& l) {
   if (not l.empty()) {
      list<ParInt>::const_iterator it = l.begin();
      while (it != l.end()) {
         // it -> escriure(); // (*it).escriure()
         cout << *it << endl;
      }
   } else {
      cout << endl;
   }
}