#include <iostream>
#include <list>
#include "LlistaIOParInt.hh"
#include "ParInt.hh"
using namespace std;

typedef list<ParInt>::const_iterator C_It;

int main() {
   int n;
   list<ParInt> l;
   LlegirLlistaParInt(l);
   cin >> n;

   int freq, sum;
   freq = sum = 0;
   for (C_It it = l.begin(); it != l.end(); ++it) {
      if (it->primer() == n) {
         ++freq;
         sum += it->segon();
      }
   }

   cout << n << ' ' << freq << ' ' << sum << endl;
}