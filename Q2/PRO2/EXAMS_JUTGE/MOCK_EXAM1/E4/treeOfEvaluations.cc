#include "treeOfEvaluations.hh"

bool evaluate(const BinTree<string> t) {
   if (t.value() == "and") return evaluate(t.left()) && evaluate(t.right());
   else if (t.value() == "or") return evaluate(t.left()) || evaluate(t.right());
   else if (t.value() == "not") return !evaluate(t.left());
   
   return t.value() == "true" ? true : false;
   // Al ser t no buit no cal comprobar que t no ho sigui, doncs la funcio sempre acabara
   // en el cas "true" o "false".
}

BinTree<bool> treeOfEvaluations(BinTree<string> t) {
   if (t.value() == "true") return BinTree<bool>(true);
   else if (t.value() == "false") return BinTree<bool>(false);

   else if (t.value() == "not") {
      return BinTree<bool>(evaluate(t), treeOfEvaluations(t.left()), BinTree<bool>());
   }
   else return BinTree<bool>(evaluate(t), treeOfEvaluations(t.left()), treeOfEvaluations(t.right()));
}