//P50036 Horner scheme
#include <iostream>
#include <vector>
using namespace std;

int evaluate(const vector<int>& p, int x) {
   int l = p.size();
   int r = p[l - 1];
   for (int i = l - 2; i >= 0; --i) {
      r *= x; //     If exists another term, multiply all by x
      r += p[i]; //  and add it as an independent ternm.
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