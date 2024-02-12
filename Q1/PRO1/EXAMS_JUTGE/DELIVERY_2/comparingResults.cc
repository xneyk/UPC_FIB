#include <iostream>
using namespace std;

int main() {
   /**
    * Asumiendo la entrada en el siguiente formato, donde todos los numeros son naturales.
    * NUM1 OPERADOR NUM2 COMPARADOR NUM3
    * OPERADOR debe ser {+,-,*}
    * COMPARADOR debe ser {<,>,<=,>=,==,!=}
   */
   int n1, n2, n3;
   char op;
   string comp;
   
   while (cin >> n1 >> op >> n2 >> comp >> n3) {
      int r1 = 0;

      // Decidiendo el operador que usaremos segun el caracter del OPERADOR
      if (op == '+') r1 = n1 + n2;
      if (op == '-') r1 = n1 - n2;
      if (op == '*') r1 = n1 * n2;

      // Decidiendo la comparación y el resultado
      if (comp == "<") {
         if (r1 < n3) {
            cout << "true" << endl;
         } else {
            cout << "false" << endl;
         }
      }
      if (comp == "<="){
         if (r1 <= n3) {
            cout << "true" << endl;
         } else {
            cout << "false" << endl;
         }
      }
      if (comp == ">") {
         if (r1 > n3) {
            cout << "true" << endl;
         } else {
            cout << "false" << endl;
         }
      }
      if (comp == ">=") {
         if (r1 >= n3) {
            cout << "true" << endl;
         } else {
            cout << "false" << endl;
         }
      }
      if (comp == "==") {
         if (r1 == n3) {
            cout << "true" << endl;
         } else {
            cout << "false" << endl;
         }
      }
      if (comp == "!=") {
         if (r1 != n3) {
            cout << "true" << endl;
         } else {
            cout << "false" << endl;
         }
      }
   }
}