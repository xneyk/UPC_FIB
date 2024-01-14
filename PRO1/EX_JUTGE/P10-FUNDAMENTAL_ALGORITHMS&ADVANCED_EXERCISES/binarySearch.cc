//P81966 Dichotomic search
#include <iostream>
#include <vector>
using namespace std;

/**
 * PRE: v is sorted in strictly increasing order. 0 ≤ left ≤ size of v and −1 ≤ right < size of v.
 * POST: returns the index that v[index] == x, -1 if it's not found.
*/
int position(double x, const vector<double>& v, int left, int right) {
   int middle = (left + right)/2;
   if (left <= right) {
      if (x == v[middle]) return middle;
      else if (x > v[middle]) return position(x, v, middle + 1, right);
      else if (x < v[middle]) return position(x, v, left, middle - 1);
   }

   return -1; // x NOT FOUND INSIDE v
}

int main() {
   int n;
   cin >> n;
   int left = 0, right = n - 1;
   vector<double> v(n);
   for (int i = 0; i < n; ++i) cin >> v[i];

   double x;
   while (cin >> x) {
      cout << position(x, v, left, right) << endl;
   }
}