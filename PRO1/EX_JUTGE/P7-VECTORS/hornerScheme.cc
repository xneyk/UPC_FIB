//P50036 Horner scheme
#include <iostream>
#include <vector>
using namespace std;

int evaluate(const vector<int>& p, int x) {
   int l = p.size();
   int x_pow = x;
   int r = p[0]; // at least the result will be the independent term.
   for (int i = 1; i < l; ++i) {
      r += p[i]*x_pow; //evaluate grade i expresion
      x_pow *= x; //prepare x for the next iterations
   }
   return r;
}

int main() {
   int n, x;
   cin >> n;
   vector<int> v(n);
   for (int i = 0; i < n; ++i) cin >> v[i];
   cout << "VECTOR READED!" << endl;
   while (cin >> x) cout << evaluate(v, x) << endl;
}