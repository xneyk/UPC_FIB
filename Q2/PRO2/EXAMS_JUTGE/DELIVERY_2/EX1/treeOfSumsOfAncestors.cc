#include "treeOfSumsOfAncestors.hh"

BinTree<int> treeOfSumsOfAncestors(const BinTree<int> t) {
   if (!t.empty()) {
      BinTree<int> t_left = t.left();
      if (!t_left.empty()) {
         t_left = BinTree<int>(t_left.value() + t.value(), t_left.left(), t_left.right());
      }

      BinTree<int> t_right = t.right();
      if (!t_right.empty()) {
         t_right = BinTree<int>(t_right.value() + t.value(), t_right.left(), t_right.right());
      }

      return BinTree<int>(t.value(), treeOfSumsOfAncestors(t_left), treeOfSumsOfAncestors(t_right));
   }
   return t;
}