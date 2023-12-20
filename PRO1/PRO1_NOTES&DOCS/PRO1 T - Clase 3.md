#Teoría

En continuidad con lo que ya hemos visto en las clases de laboratorio, tanto en la [Clase 3](PRO1%20L%20-%20Clase%203.md) como en la [Clase 4](PRO1%20L%20-%20Clase%204.md)
# Secuencias

Una secuencia es un conjunto de elementos de **un único tipo de datos** determinado.

Lo que queremos conseguir ahora, es, dada una secuencia, realizar una tarea sobre TODOS sus elementos.

> Significa esto que tenemos que almacenar todos los elementos de la secuencia? **No** solo almacenaremos la información que necesitemos

## Resolución de un problema de este tipo

**A:** ¿Que información necesito mantener de la parte tratada de la secuencia?
**B:** ¿Cómo actualizo esa información para que el elemento actual pase a estar incluido en la parte tratada?
**C:** ¿Como detecto que se ha tratado toda la secuencia?  (condición del bucle)
**D:** ¿Cómo inicializo esa información manteniendo sus significado? (instrucciones antes del bucle)

```cpp
int main() {
	D
	while (C) {
		B
	}
}
```

**Ejemplo:**
Queremos tratar una secuencia y determinar el máximo ```max()```.

Dividiremos un esquema de secuencia en tres partes:
- Parte tratada: Elementos anteriores
- Elemento actual: El cual estamos tratando ahora
- Parte a tratar: Siguientes elementos (no sabemos cuales son)

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	int max = 0;
	
	while (cin >> n) {
		if(n > max) max = n;
	}
}
```

De este modo, no nos acordamos de todos los elementos de la parte tratada, sino que nos acordamos de cual era el máximo anterior y solamente lo actualizamos.

# Distintas maneras de tratar una secuencia

Si **NO** nos dicen que la secuencia no puede ser vacía, asumiremos que una secuencia vacía es una entrada valida (*y muy seguramente sea uno de los test privados*). Entonces no podremos asumir que el primer valor de la secuencia exista.

Si nos dicen que la secuencia no es vacía, podemos leer el primer elemento antes de entrar al bucle, pues existe seguro.

## Recorrido
Al hecho de tratar toda la secuencia se le llama **RECORRIDO**. Estaremos escuchando el siguiente elemento de la secuencia hasta que esta se acabe (El usuario use el comando ```CRTL + D``` para terminar la ejecución del programa.
## Búsqueda
Para cuando nos pidan si en la secuencia se cumple una condición (buscamos **si algún** elemento cumple con una propiedad) estaremos haciendo una búsqueda.

De este modo, lo que haremos será:
1. Escuchar el elemento actual de la secuencia
2. Comprobar si cumple con la propiedad (condición)
	* Si la cumple: salimos del bucle ¡LO HEMOS ENCONTRADO!
	* No la cumple: seguimos escuchando el siguiente elemento de la secuencia

**Ejemplo:**

```
Dada una secuencia de naturales, dí si existe un numero par en esta.
```

```cpp
int main() {
	int n;
	bool found = false; 
	// En un inicio no hemos encontrado el elemento

	// C++ evalua las expresiones booleanas de izquierda a 
	// derecha, por lo tanto si found == true, directamente
	// no compueva el cin >> n;
	
	// ESTE MODO ES MAS EFICIENTE, PUES NO LEES UN ELEMENTO
	// DE MÁS.
	
	while (not found and cin >> n) {
		if(n % 2 == 0) found = true;
		// Tan temprano como un elemento de la secuencia
		// sea un numero par, saldremos del bucle.
		// NO ESCUCHAREMOS LOS SIGUIENTES ELEMENTOS.
	}
	
	if(found) {
		cout << "Encontrado" << endl;
	} else {
		cout << "No se ha encontrado" << endl;
	}
}
```
