#Laboratorio
# Secuencias avanzadas

En una secuencia, puede darse el caso en el que tenga que leer los datos de dos en dos. Por ejemplo, articulo - cantidad.

esto no tiene mayor complicación que leer de este modo:

```cpp
while (cin >> articulo >> cantidad) {
	//Tratamiento
}
```

La cosa se complica cuando no podemos leer de dos en dos, sino que debemos leer 2 o más al inicio y luego ir avanzando de a uno.

*A la técnica usada en el ejemplo que encontramos a continuación le podemos llamar efecto ventana.*

**Ejemplo:** Queremos buscar un pico en un gráfico, por lo que la manera de encontrarlo será: Siendo a, b, c naturales consecutivos en el gráfico, si b>a i b<c, entonces b es un pico.

![Graph](Graph_LabClass5.png)

Primero que todo nos encontramos ante un esquema de búsqueda. Por ende, una vez se cumpla la condición se acaba el bucle.

```cpp
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	bool found = false;
	cin >> a >> b;
	
	while (not found and cin >> c) {
		if ((a < b) and (b > c)) {
			cout << "YES" << endl;
			found = true;
		} else {
         a = b;
         b = c;
      }
	}
   if (not found) cout << "NO" << endl;
}
```

De este modo, conseguimos conservar los dos datos anteriores y añadir un dato más, dando este efecto de mover la ventana una variable hacia la derecha.