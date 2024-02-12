//P71310 Scalar product
#include <iostream>
#include <vector>
using namespace std;

/**
 * PRE: The vectors u and v have the same size.
*/
double scalar_product(const vector<double>& u, const vector<double>& v) {
   int l = u.size(); // equal to v.size()
   double r = 0;
   for (int i = 0; i < l; ++i) r += u[i]*v[i];
   return r;
}