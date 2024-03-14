#ifndef LlistaIOParInt
#define LlistaIOParInt

#include <iostream>
#include <list>
#include "ParInt.hh"
using namespace std;

/**
 * PRE: l és buida; el canal estandar d’entrada conté un nombre parell d’enters, acabat pel parell 0 0
 * POST: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)
*/
void LlegirLlistaParInt(list<ParInt>& l);

/**
 * PRE: cert
 * POST: s’han escrit al canal estandar de sortida els elements de l
*/
void EscriureLlistaParInt(const list<ParInt>& l);


#endif