#include "execute.hh"

int evaluate(map<string,int> &var2val, BinTree<string> t) {
   if (t.value() == "+") {
      return (evaluate(var2val, t.left()) + evaluate(var2val, t.right())) % 10;
   }
   else if (t.value() == "*") {
      return (evaluate(var2val, t.left()) * evaluate(var2val, t.right())) % 10;
   }
   else if ("0" <= t.value() and t.value() <= "9") {
      return t.value()[0] - '0';
   }
   else {
      return var2val[t.value()];
   }
}

void execute(map<string,int> &var2val, BinTree<string> t) {
   if (!t.empty()) {
      if (t.value() == "list") {
         execute(var2val, t.left());
         execute(var2val, t.right());
      }
      else if (t.value() == "if") {
         if (evaluate(var2val, t.left()) != 0) execute(var2val, t.right());
      }
      else if (t.value() == "while") {
         while (evaluate(var2val, t.left()) != 0) {
            execute(var2val, t.right());
         }
      }
      else if (t.value() == "=") {
         var2val[t.left().value()] = evaluate(var2val, t.right());
      }
      else if (t.value() == "print") {
         cout << evaluate(var2val, t.left()) << endl;
      }
   }
}