#include <vector>
using namespace std;

struct parint {
   int prim, seg;
};

/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
parint max_min1(const vector<int> &v) {
   int l = v.size();
   parint max_min;
   max_min.prim = max_min.seg = v[0];
   /**
    * max: max_min.prim
    * min: max_min.seg
   */
   for (int i = 1; i < l; ++i) {
      if (v[i] > max_min.prim) max_min.prim = v[i];
      else if (v[i] < max_min.seg) max_min.seg = v[i];
   }

   return max_min;
}

/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
pair<int, int> max_min2(const vector<int> &v) {
   int l = v.size();
   pair<int, int> max_min;
   max_min.first = max_min.second = v[0];
   /**
    * max: max_min.prim
    * min: max_min.seg
   */
   for (int i = 1; i < l; ++i) {
      if (v[i] > max_min.first) max_min.first = v[i];
      else if (v[i] < max_min.second) max_min.second = v[i];
   }

   return max_min;
}

/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
void max_min3(const vector<int> &v, int &x, int &y) {
   int l = v.size();
   x = y = v[0];

   for (int i = 0; i < l; ++i) {
      if (v[i] > x) x = v[i];
      else if (v[i] < y) y = v[i];
   }
}