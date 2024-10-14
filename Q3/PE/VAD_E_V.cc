// program for calulating E(X) and V(X)
#include <iostream>
#include <map>

void read_model(std::map<int, double> &p_x, int argc, char **argv) {
   for (int i = 1; i < argc; ++i) p_x[i] = atof(argv[i]);
}

double calc_E(const std::map<int, double> &p_x, int b, int e) {
   double r = 0;
   for (int i = b; i <= e; ++i) r += i*p_x.at(i);
   return r;
}

double calc_V(std::map<int, double> p_x, double E_x, int b, int e) {
   double r = 0;
   for (int i = b; i <= e; ++i) r += (i-E_x)*(i-E_x)*p_x.at(i);
   return r;
}

int main(int argc, char **argv) {
   std::map<int, double> p_x;
   read_model(p_x, argc, argv);

   double E_x = calc_E(p_x, 1, argc - 1);
   std::cout << "E(X) := " << E_x << " V(X) := " << calc_V(p_x, E_x, 1, argc - 1) << std::endl;
}