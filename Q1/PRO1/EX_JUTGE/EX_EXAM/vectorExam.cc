#include <iostream>
#include <vector>
using namespace std;

int absolute(int x) {
   if (x < 0) return -x;
   else return x;
}

/**
 * PRE: |v| es par y >= 2;
*/
bool check_distance(const vector<int>& v, int n) {
   int dist = absolute(v[0] - v[1]);
   for (int i = 2; i < n; i += 2) {
      if (dist >= absolute(v[i] - v[i+1])) return false;
   }
   return true;
}

void ini_v(vector<int>& v, int n) {
   for (int i = 0; i < n; ++i) cin >> v[i];
}

int main () {
   int n;
   cin >> n;
   vector<int> v(n);
   ini_v(v, n);

   check_distance(v, n) ? cout << "SI:)" : cout << "NO:(";
   cout << endl;
}