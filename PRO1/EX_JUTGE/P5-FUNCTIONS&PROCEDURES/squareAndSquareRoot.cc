#include <cmath>
#include <iostream>
using namespace std;

int main() {
   cout.setf(ios::fixed);
   cout.precision(6);
   
   int x;
   
   while (cin >> x) cout << x*x << ' ' << sqrt(double(x)) << endl;
}