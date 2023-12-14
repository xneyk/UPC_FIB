//P87920 Equal to the sum of the rest (II)
#include <iostream>
#include <vector>
using namespace std;

void ini_vector(vector<int>& v, int l) {
   for (int i = 0; i < l; ++i) cin >> v[i];
}

/**
 * PRE: i is the index of the element we need to omit
 * POST: returns the sum of all elements minus v[i];
*/
int check_sum(const vector<int>& v, int i) {
   int l = v.size();
   int r = 0;
   for (int j = 0; j < l; ++j) {
      if(j != i) r+= v[j];
   }
   return r;
}

int main() {
   int n;
   while (cin >> n) {
      vector<int> v(n);
      ini_vector(v, n);
      bool found = false;
      int i = 0;
      while (i < n and not found) {
         found = v[i] == check_sum(v, i);
         ++i;
      }
      if (found) cout << "YES" << endl;
      else cout << "NO" << endl;
   }
}