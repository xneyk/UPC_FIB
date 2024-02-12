//P29094 Position of the maximum
#include <iostream>
#include <vector>
using namespace std;

/**
 * PRE: 0 <= m < size of v.
 * POST: returns index of the max element in v between 0 and m.
*/
int position_maximum(const vector<double>& v, int m) {
   int max_pointer = 0;
   for (int i = 1; i <= m; ++i) {
      if (v[i] > v[max_pointer]) max_pointer = i;
   }
   return max_pointer;
}