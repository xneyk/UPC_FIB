#include "Estudiant.hh"

const char *ER1 = "No te nota";
const char *ER2 = "Valor de la nota entre 0 a 10";
const char *ER3 = "Ja te nota";
const char *ER4 = "El DNI es incorrecte";

/**
 * CONSTRUCTORES:
*/

Estudiant::Estudiant() {
   dni = 0;
   nota = -1;
}

Estudiant::Estudiant(int dni) {
   if (dni < 0) throw PRO2Excepcio(ER4);
   this->dni = dni;
   nota = -1;  // L'estudiant no te nota
}

/**
 * MODIFICADORES:
*/

void Estudiant::afegir_nota(double nota) {
   if (this->nota != -1) throw PRO2Excepcio(ER3);
   if (nota < 0 or MAX_NOTA < nota) throw PRO2Excepcio(ER2);
   this->nota = nota;
}

void Estudiant::modificar_nota(double nota) {
   if (this->nota == -1) throw PRO2Excepcio(ER1);
   if (nota < 0 or MAX_NOTA < nota) throw PRO2Excepcio(ER2);
   this->nota = nota;
}

/**
 * CONSULTORES:
*/

int Estudiant::consultar_DNI() const {
   return dni;
}

double Estudiant::consultar_nota() const {
   if (nota == -1) throw PRO2Excepcio(ER1);
   return nota;
}

double Estudiant::nota_maxima() {
   return MAX_NOTA;
}

bool Estudiant::te_nota() const {
   return nota != -1;
}

bool Estudiant::comp(const Estudiant& e1, const Estudiant& e2) {
   return e1.dni < e2.dni;
}

bool Estudiant::operator==(const Estudiant& est) const {
   return dni == est.dni;
}

bool Estudiant::operator!=(const Estudiant& est) const {
   return dni != est.dni;
}

/**
 * IO:
*/

void Estudiant::llegir() {
   cin >> dni;
   if (dni < 0) throw PRO2Excepcio(ER4);
   cin >> nota;
   if (nota < 0 or MAX_NOTA < nota) nota = -1;
}

void Estudiant::escriure() const {
   cout << dni << " ";
   nota != -1 ? cout << nota : cout << "NP";
   cout << endl;
}