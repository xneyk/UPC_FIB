# Trata strings como entradas de datos

Created: March 20, 2024 6:04 PM
Tags: C++, data_treatment, string

# istringsteam

Imaginemos que necesitamos tratar un string como si fuera una entrada de datos como lo solemos hacer con cin >> data. Veamos un ejemplo de como el objecto istringstream de la libreria standard sstream nos puede ayudar a transformar un string en un *input object*

```cpp
//inclusion de la libreria
#include <sstream> 
using namespace std;

string people_list = "Juan Alba Maria Isabel Ricardo";
istringstream iss_people_list(people_list);
/*
iss_people_list es un input object por lo que se puede usar de modo similar a como
usamos cin, el cual no deja de ser un input object con la diferencia que este 
extralos datos del canal standar, el cual es el terminal.

Veamos entonces como podriamos ahora insertar todos estos nombres en un vector donde
cada casilla sea un string con un solo nombre:
*/

vector<string> procesed_people;
string aux;
while (iss_people_list >> aux) {
	procesed_people.push_back(aux);
}
```