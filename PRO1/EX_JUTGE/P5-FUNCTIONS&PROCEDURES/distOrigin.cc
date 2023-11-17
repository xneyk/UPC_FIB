#include <iostream>
#include <cmath>
using namespace std;


double dist_or(double x,double y);

int main() {
  double x,y;
  while (cin >> x >> y) cout << dist_or(x,y) << endl;
}

double dist_or(double x,double y) {
  /**
   * La distancia a l'origen del punt a l'espai (x,y) es el modul del vector
   * que va desde (0,0) fins a (x, y), es a dir, del vector (x,y).
  */
  return sqrt(x*x + y*y);
}