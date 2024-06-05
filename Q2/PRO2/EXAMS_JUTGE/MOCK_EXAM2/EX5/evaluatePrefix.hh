#include <iostream>
#include <string>

using namespace std;

#include "BinTree.hh"

void reverse(string &word) {
   int i = 0, j = word.size() - 1;
   while (i < j) {
      char aux = word[i];
      word[i] = word[j];
      word[j] = aux;
      ++i; --j;
   }
}

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre strings de lletres minúscules i els operadors Concat, Reverse.
//       n>=0
// Post: Retorna el prefix de longitut n de l'avaluació de l'expressió representada per t.
//       En cas que n sigui més gran que la longitut d'aquesta avaluació,
//       llavors retorna només l'avaluació, cap caràcter més.
string evaluatePrefix(BinTree<string> t) {
   if (!t.value().empty()) {
      if (t.value() == "Concat") {
         return evaluatePrefix(t.left()).append(evaluatePrefix(t.right()));
      }
      if (t.value() == "Reverse") {
         string left = evaluatePrefix(t.left());
         reverse(left);
         return left;
      }
      // base case
      return t.value();
   }
   return "";
}

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre strings de lletres minúscules i els operadors Concat, Reverse.
//       n>=0
// Post: Retorna el prefix de longitut n de l'avaluació de l'expressió representada per t.
//       En cas que n sigui més gran que la longitut d'aquesta avaluació,
//       llavors retorna només l'avaluació, cap caràcter més.
string evaluatePrefix(BinTree<string> t, int n) {
   string res = "";
   if (!t.value().empty()) res = evaluatePrefix(t);
   return res;
}