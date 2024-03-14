#include <iostream>
#include <list>
using namespace std;

/**
 * PRE: uno = U
 * POST: uno pasa a ser la interseccion de U y dos
*/
void inter(list<int>& uno, const list<int>& dos) {
   list<int>::iterator it_uno = uno.begin();
   list<int>::const_iterator it_dos = dos.begin();
   
   while (it_uno != uno.end() and it_dos != dos.end()) {
      if (*it_uno < *it_dos) it_uno = uno.erase(it_uno);
      else if (*it_uno > *it_dos) ++it_dos;
      else { // *it_uno == *it_dos
      // En la interseccion se conserva el elemento
         ++it_uno;
         ++it_dos;
      }
   }
   while (it_uno != uno.end()) it_uno = uno.erase(it_uno);
}