#include "searchInBST.hh"

bool searchInBST(BinTree<int> t, int x) {
   if (t.empty()) return false;
   
   if (x < t.value()) return searchInBST(t.left(), x);
   if (x > t.value()) return searchInBST(t.right(), x);
   return true; // x es exactament igual a t.value()
}