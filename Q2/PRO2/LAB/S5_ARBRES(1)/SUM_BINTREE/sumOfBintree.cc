#include "sumOfTree.hh"

int sumOfTree(BinTree<int> t) {
   if (t.empty()) return 0;
   return t.value() + sumOfTree(t.left()) + sumOfTree(t.right());
}