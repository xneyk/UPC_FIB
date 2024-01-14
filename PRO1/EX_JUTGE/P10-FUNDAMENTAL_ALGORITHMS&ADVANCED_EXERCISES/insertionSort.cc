//P41412 Insertion sort
#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<double>& v) {
   int n = v.size();
   for (int i = 1; i < n; ++i) {
      int j = i;
      double x = v[j]; //guardem l'element a inserir per buscar el seu lloc.
      while (j > 0 and x < v[j-1]) {
         v[j] = v[j-1]; //simula el desplaçar l'element a la dreta.
         --j;
      }
      v[j] = x; //insercció
   }
}