#include <iostream>
using namespace std;

// Pre: d1, d2 > 0.
// Post: returns true if  n1/d1 < n2/d2 and false in other case.
bool c_frac(int n1, int d1, int n2, int d2);

int main() {
   int x, d1, y, d2;
   while (cin >> x >> d1 >> y >> d2) cout << c_frac(x, d1, y, d2);
}

bool c_frac(int n1, int d1, int n2, int d2) {
   return n1*d2 < n2*d1;
}