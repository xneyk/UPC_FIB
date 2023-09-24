#include <iostream>
using namespace std;

int main()
{
   int n; // Siendo n un numero natural expresado en segundos (Entrada)
   int h, m, s; // Siendo h horas, m minutos y s segundos (Salidas)

   cin >> n;

   h = n / 3600; //Paquetes de 3600 segundos serán las horas
   m = (n % 3600) / 60; // Todos los segundos de los que no pueda hacer paquetes de hora serán minutos
   s = n % 60; // Todo lo que sobre de paquetes de 60 (minutos) seràn segundos.

   cout << h << ' ' << m << ' ' << s << endl;
}