//P67268 Reverse of sequences
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int l;
   while (cin >> l) {
      vector<int> v(l);
      for (int i = 0; i < l; ++i) cin >> v[i];

      for (int i = l - 1; i >= 0; --i) {
         cout << v[i];
         if (i > 0) cout << ' '; //Add separation if it isn't the last element.
      }
      cout << endl;
   }
}