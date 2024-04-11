#include "treeOfSums.hh"

BinTree<int> treeOfSums(BinTree<int> t) {
   if (!t.empty()) {
      BinTree<int> t_left = treeOfSums(t.left());
      BinTree<int> t_right = treeOfSums(t.right());
      
      if (t_left.empty() && t_right.empty()) return BinTree<int> (t.value());
      else if (t_left.empty() && !t_right.empty()) {
         return BinTree<int> (t.value() + t_right.value(), t_left, t_right);
      }
      else if (!t_left.empty() && t_right.empty()) {
         return BinTree<int> (t.value() + t_left.value(), t_left, t_right);
      }
      else return BinTree<int> (t.value() + t_left.value() + t_right.value(), t_left, t_right);
   }

   return t;
}