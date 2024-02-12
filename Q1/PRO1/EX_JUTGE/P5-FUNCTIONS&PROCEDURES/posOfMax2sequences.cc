#include <iostream>
using namespace std;

/**
 * PRE: max = 0;
*/
void infoSequencia(int& max, int& lpos);

/**
 * PRE: item --> element to search for
 * POST: returns the pos of the item, -1 in case that item does not apear.
*/
int search(int item);

int main() {
   int max = 0, lpos = 0;
   infoSequencia(max, lpos); // Treu l'info per buscar a la secona secuencia
   cout << max << ' ' << lpos << ' ';
   int search_result = search(max);
   if (search_result > 0) cout << search_result << endl;
   else cout << '-' << endl;
}

void infoSequencia(int& max, int& lpos) {
   int i = 0;
   int element;
   while (cin >> element and element != 0) {
      ++i;
      if (element >= max) {
         max = element;
         lpos = i;
      }
   }
}

int search(int item) {
   int x, i = 0;
   while (cin >> x and x != 0) {
      ++i;
      if (x == item) return i;
   }
   return -1;
}