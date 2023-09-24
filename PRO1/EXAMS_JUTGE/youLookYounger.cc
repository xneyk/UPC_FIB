#include <iostream>
using namespace std;

int main() {
   // Cada variable correspon a una paraula de la sequencia
   string a, b, c, name, d, e, f, g, h;
   int n;

   while (cin >> a >> b >> c >> name >> d >> e >> f >> n >> g >> h) {
      n -= n / 10;
      cout << name << ", you look younger. I thought you were " << n << " years old." << endl;
   }
}