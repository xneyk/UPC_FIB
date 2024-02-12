//P24730 Nursery school
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * MEJOR_PROFE: 
 *    1. Mas caramelos de
 *    2. Mas zanaorias de
 *    3. Nombre mas corto
 *    4. Nombre mas pequeño lexicograficamente
*/

struct Teacher {
   string name;
   int sweet;
   int carrot;
};

vector<Teacher> read_teachers(int n) {
   vector<Teacher> v(n);
   for (int i = 0; i < n; ++i) {
      cin >> v[i].name >> v[i].sweet >> v[i].carrot;
   }
   return v;
}

//Paso por referencia, uno de los parametros es un string.
bool better_teacher(const Teacher& a, const Teacher& b) {
   if (a.sweet != b.sweet) return a.sweet > b.sweet;
   else if (a.carrot != b.carrot) return a.carrot > b.carrot;
   else if (a.name.size() != b.name.size()) return a.name.size() < b.name.size();
   else return (a.name < b.name);
}

int main() {
   int n;
   cin >> n; //n casos
   for (int i = 0; i < n; ++i) {
      int p;
      cin >> p;
      vector<Teacher> teachers = read_teachers(p); //Lista de p profesores
      sort(teachers.begin(), teachers.end(), better_teacher);
      for (int j = 0; j < p; ++j) cout << teachers[j].name << endl;
      cout << endl;
   }
}