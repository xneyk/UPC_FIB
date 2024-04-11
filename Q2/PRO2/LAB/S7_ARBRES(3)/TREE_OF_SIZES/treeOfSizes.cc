#include "treeOfSizes.hh"

BinTree<int> treeOfSizes(BinTree<int> t) {
   if (!t.empty()) {
      int root_value = 0;
      BinTree<int> t_left = t.left();
      BinTree<int> t_right = t.right();
      if (!t.left().empty()) {
         t_left = treeOfSizes(t_left);
         root_value += t_left.value();
      }
      if (!t.right().empty()) {
         t_right = treeOfSizes(t_right);
         root_value += t_right.value();
      }
      return BinTree<int> (root_value + 1, t_left, t_right);
   }

   return t;
}