#Laboratorio
# Como fijar el numero de decimales de una salida por consola.

En ocasiones, no nos interesará mostrar la máxima precisión en la que se puede expresar un número, sino por ejemplo, su versión con solamente dos decimales.

Para conseguir lo anterior mencionado nos fijaremos en el siguiente ejemplo:
```cpp 
#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	/* En el lugar del 2, escribiremos el
	numero de decimales que nosotros deseemos mostrar. */
}
```

# Tratamiento secuencial

Cuando nos interesa que los datos se procesen a medida que van entrando, lo haremos del siguiente modo:

```cpp
int x;

while (cin >> x) {
	// Tratamiento del dato
}
```

Si queremos analizar que esta pasando en este bucle, vamos a ver que sigue este procedimiento:

1. Pide el dato
2. Entra al bucle y ejecuta el bloque del bucle
3. Acaba el bucle y vuelve a la linea donde se encuentra la palabra clave ```while```.
5. Vuelve al punto ```1.```
