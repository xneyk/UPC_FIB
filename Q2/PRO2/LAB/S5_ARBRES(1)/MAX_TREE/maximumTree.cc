#include "maximumTree.hh"

int max_root(BinTree<int> a1, BinTree<int> a2) {
   return a1.value() > a2.value() ? a1.value() : a2.value();
}

BinTree<int> maximumTree(BinTree<int> a1, BinTree<int> a2) {
   if (!a1.empty() && !a2.empty()) {
      return BinTree<int>(max_root(a1, a2), maximumTree(a1.left(), a2.left()), maximumTree(a1.right(), a2.right()));
   }
   else if (!a1.empty()) return BinTree<int>(a1.value(), a1.left(), a1.right());
   else if (!a2.empty()) return BinTree<int>(a2.value(), a2.left(), a2.right());
   else return a1;
}