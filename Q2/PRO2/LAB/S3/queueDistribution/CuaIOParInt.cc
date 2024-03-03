#include "CuaIOParInt.hh"

void llegirCuaParInt(queue<ParInt>& c) {
   ParInt p;
   while (p.llegir()) c.push(p);
}

void escriureCuaParInt(queue<ParInt> c) {
   int n = c.size();
   for (int i = 0; i < n; ++i) {
      ParInt p = c.front();
      p.escriure(); 
      
      c.pop();
      c.push(p);
   }
}

