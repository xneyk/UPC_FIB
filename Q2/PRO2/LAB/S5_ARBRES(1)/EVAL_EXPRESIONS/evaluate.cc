#include "evaluate.hh"
#include "utils.hh"

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors +,-,*.
//       Les operacions no produeixen errors d'overflow.
// Post: Retorna l'avaluació de l'expressió representada per t.
int evaluate(BinTree<string> t) {
   if (not t.empty()) {
      if (isDigit(t.value()[0])) { // Si no es empty i es un nombre com a minim te long = 1.
         return mystoi(t.value());
      } else { // Es un operador {+,-,*}
         if (t.value()[0] == '+') return evaluate(t.left()) + evaluate(t.right());
         else if (t.value()[0] == '-') return evaluate(t.left()) - evaluate(t.right());
         else if (t.value()[0] == '*') return evaluate(t.left()) * evaluate(t.right());
      }
   }
   return 0;
}