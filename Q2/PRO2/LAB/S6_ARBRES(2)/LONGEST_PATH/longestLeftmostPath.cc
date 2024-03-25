#include "longestLeftmostPath.hh"

list<int> longestLeftmostPath(BinTree<int> t) {
   list<int> left;
   list<int> right;

   if (!t.empty()) {
      left = longestLeftmostPath(t.left());
      left.push_front(t.value());
      right = longestLeftmostPath(t.right());
      right.push_front(t.value());
   }

   if (left.size() >= right.size()) return left;
   else return right;
}