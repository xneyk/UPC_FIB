#include <iostream>
#include <queue>
#include "ParInt.hh"
#include "CuaIOParInt.hh"
using namespace std;

struct SubQueue {
   queue<ParInt> subqueue;
   int time_pass_through;
};

/**
 * PRE:  cert
 * POST: retorna cert si la primera cua es millor cua, fals en cas contrari.
 *       s'enten com a millor cua aquella on esperare menys temps.
*/
bool betterQueue (const SubQueue &q1, const SubQueue &q2) {
   return q1.time_pass_through <= q2.time_pass_through;
}

/**
 * PRE: q es una cua no buida
 * POST: q es buida i a quedat dividida en q1 i q2 seguint les regles de betterQueue().
*/
void divideQueue (queue<ParInt> &q, SubQueue &q1, SubQueue &q2) {
   while (not q.empty()) {
      if (betterQueue(q1, q2)) {
         q1.subqueue.push(q.front());
         q1.time_pass_through += q.front().segon();
      } else { //Es triga menys per la segona cua.
         q2.subqueue.push(q.front());
         q2.time_pass_through += q.front().segon();
      }

      q.pop();
   }
}

int main() {
   queue<ParInt> q;
   llegirCuaParInt(q);
   
   SubQueue q1, q2;
   q1.time_pass_through = q2.time_pass_through = 0;
   
   divideQueue(q, q1, q2);

   escriureCuaParInt(q1.subqueue);
   cout << endl;
   escriureCuaParInt(q2.subqueue);
}