#ifndef CuaIOParInt
#define CuaIOParInt

#include <iostream>
#include <queue>
#include "ParInt.hh"

/**
 * PRE: c és buida; el canal estandar d’entrada conté un nombre parell d’enters, acabat pel parell 0 0
 * POST: s’han encuat a c els elements llegits fins al 0 0 (no inclòs)
*/
void llegirCuaParInt(queue<ParInt>& c);

/**
 * PRE: cert
 * POST:s’han escrit al canal estandar de sortida els elements de c
*/
void escriureCuaParInt(queue<ParInt> c);

#endif