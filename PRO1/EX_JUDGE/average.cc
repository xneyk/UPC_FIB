#include <iostream>
using namespace std;

int main(){
    int a, b;

    //cout << "Entra dos numeros para buscar su promedio: " << endl;
    cin >> a >> b;
    cout << (a+b)/2.0 << endl; /*
      També hagués estat una opció (més llegible inclós) crear una variable r/result de la següent manera:
         double r;
         r = (a+b)/2;
      No obstant això, estariem reservarnt un espai en memoria per solucionar un problema que té una solució tant simple com dividir entre 2.0, fent que el resultat hagi de ser double a la força.
   */
}