#include "reverseTree.hh"

// Pre:  
// Post: retorna el revessat de t.
BinTree<int> reverseTree(BinTree<int> t) {
   if (!t.empty()) return BinTree<int>(t.value(), reverseTree(t.right()), reverseTree(t.left()));
   return t;
}