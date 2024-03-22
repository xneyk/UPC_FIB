#include "evaluate.hh"
#include "utils.hh"

int evaluate(map<string,int> &variable2value, BinTree<string> t){
   if (!t.empty()) {
      if (t.value() == "+") return evaluate(variable2value, t.left()) + evaluate(variable2value, t.right());
      if (t.value() == "-") return evaluate(variable2value, t.left()) - evaluate(variable2value, t.right());
      if (t.value() == "*") return evaluate(variable2value, t.left()) * evaluate(variable2value, t.right());
      if (isNumber(t.value())) return mystoi(t.value());
      else return variable2value[t.value()];
   }
   return 0;
}