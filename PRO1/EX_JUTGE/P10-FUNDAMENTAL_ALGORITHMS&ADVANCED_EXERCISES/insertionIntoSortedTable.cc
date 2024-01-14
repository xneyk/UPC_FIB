//P98179 Insertion into a sorted table
#include <iostream>
#include <vector>
using namespace std;

void insert(vector<double>& v) {
   int i = v.size() - 1;
   while (v[i] < v[i-1] and i > 0) {
      double aux = v[i];
      v[i] = v[i-1];
      v[i-1] = aux;
      --i;
   }
}