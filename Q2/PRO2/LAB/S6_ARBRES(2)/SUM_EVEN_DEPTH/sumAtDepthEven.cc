#include "sumAtDepthEven.hh"

void sumAtDepthEven(BinTree<int> t, int &sum, int depth) {
   if (!t.empty()) {
      if (depth%2 == 0) sum += t.value();
      sumAtDepthEven(t.left(), sum, depth + 1);
      sumAtDepthEven(t.right(), sum, depth + 1);
   }
}

int sumAtDepthEven(BinTree<int> t) {
   int sum = 0;
   sumAtDepthEven(t, sum, 0);
   return sum;
}
