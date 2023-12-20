#Teoría 
# Vectores
Un vector, en el ámbito de la informática, es una secuencia de cualquier tipo de datos (todos los elementos tienen el mismo tipo de datos). 

**Características:**
* Secuencia de ```data_type```
* El tamaño puede variar (podemos aumentar y reducir su tamaño)
* Acceso directo por índice
* Los indices se numeran con ```0, 1, 2, ..., (n-1)```

En conclusión, un vector es un tipo de dato **complejo** que nos permite almacenar un conjunto de valores de cualquier tipo de datos, no obstante, todos los elementos deben ser del mismo tipo de datos.

### Sintaxis:
Siempre que queramos usar un vector debemos incluir la librería ```<vector>```, que es donde estan definidos los vectores.

```#include <vector>```

**Declaración de un vector:**

```cpp
#include <vector>

vector<T> var_name(S, I);
```

Donde...
* T: Tipo de dato que tienen los elementos.
* S: Tamaño del vector (por defecto es 0).
* I: Valor inicial de los elementos del vector (si no se indica el índice será invalido, es decir, no se puede leer).

*Si solamente se indica uno de los dos parámetros (S, I) se entenderá como S, es decir, el tamaño.*

**Ejemplo:** A continuación declaramos distintos vectores de tipo ```int```
```cpp
#include <vector>

vector<int> v1; // Vector vacio: {}
vector<int> v2(2); // Vector vacio de tamaño 2: {,}
vector<int> v3(2, 1); //Vector de tamaño 2 y todos los elementos valen 1: {1,1}
```

## Como accedo a los índices
```cpp
int main() {
	vector <int> v(3, 1) ;
	
	int x = v[0] ; // consulto valor posición 0 de v
	v[0] = 10; // actualizo su valor
}
```

Para acceder al elemento en el índice ```i``` usamos los corchetes (```[]```) como bien se indica en el ejemplo anterior. Esto se leería, elemento ```i``` del vector ```v```.

### Índices no validos:
¿Que pasaría si quiero acceder a un índice no valido?

Se entiende como índice no valido, aquel que no esta definido aún, normalmente serán el indice ```-1``` y el índice ```n-1```, es decir los que no están entre el primer y último índice válido.

Si tratamos de acceder a un índice no valido, en el mejor de los casos saltara un error: ```container with out-of-bounds```. No obstante, también podría ser que nos devuelva el valor que haya almacenado en esa posición de la RAM, como no nos dará un error, no sabremos que eso esta mal y por eso es peligroso.

## ¿Cómo se gestionan los vectores a nivel memoria?
Los elementos de un vector se almacenan en espacios de memoria consecutivos, es decir, uno seguido del otro.

Es por esta razón que los vectores tienen acceso directo por indice, pues la variable "v" de tipo vector recuerda la posición del primer elemento y solamente necesito saber cuantas veces debo desplazarme para acceder a la posición ```i```.

## Métodos de Vectores:

#### size():
El método ```size()```nos retorna el numero de elementos de un vector.
*Cuidado no confundir el tamaño del vector con el índice del último elemento. Pues si un vector tiene 5 elementos, el índice del elemento 5 es ```i = 4```*.

```cpp
// si vector mis_numeros<int> = {1, 5, 2, 7};
cout << mis_numeros.size() << endl; // 4
```
#### push_back():
El método ```push_back(data_type elem)``` añade el elemento que se le pase como parámetro, detrás del vector. Es decir...

```cpp
// si vector mis_numeros<int> = {1, 5, 2, 7};
mis_numeros.push_back(4);
// mis_numeros ahora es {1, 5, 2, 7, 4};
```

#### pop_back():
El método ```pop_back()``` elimina el último elemento del vector. Es decir...

```cpp
// si vector mis_numeros<int> = {1, 5, 2, 7};
mis_numeros.pop_back();
// mis_numeros ahora es {1, 5, 2};
```

## Lectura / Escritura de Vectores
```cin``` y ```cout``` solo soportan tipos de valores **simples**. Por lo tanto no podemos "pintar" por la terminal ni escribir en memoria un vector del siguiente modo.
```cpp
vector<T> v;
cin >> v; // ❌ ERROR de compilación: cin sólo sobre tipos de datos simples.
cout << v; // ❌ ERROR de compilación: cout sólo sobre tipos de datos simples.
```

## Hacer una copia de un Vector
El operador asignación ```=``` significa lo mismo para los vectores, no obstante, tenemos que ir con mucho cuidado.

A nivel interno, hacer una copia de un vector significa.
1. Buscar un espació de memoria donde quepan todos esos elementos.
2. Recorrer el Vector 1 para cada elemento y asignar casilla por casilla en Vector 2.

En conclusión, con los vectores tenemos que ir con cuidado con crear copias, debemos plantearnos si es necesario o no.

```cpp
// Opción 1: copia de un vector que se ha modificado a lo
// largo del código.
vector<int> v (3, 1);
(...)
vector<int> w = v;

// Opción 2: copia de un vector que se crea sin nombre.
vector<int> z;
z = vector<int> (20, 5);

// ❌ Opción 3: mala idea.
vector<int> vect (20, 5);
vector<int> copia (10, 8);
copia = vect;
```

## Vectores, Funciones y Acciones
Podemos pasar vectores como parámetros de una función del mismo modo al que hemos usado antes con datos simples. No obstante, tenemos que tener algo en cuenta...

Como bien vimos en las [Funciones & Acciones](PRO1%20T%20-%20Clase%206.md), si hacemos un paso por valor, se crea una copia de la variable parámetro en el *scope* de la función.

En el ámbito de los vectores, ya hemos visto que la copia de vectores es muy costosa, para evitar que se haga una copia vector usaremos un pequeño "truco" llamado *Paso por referencia **constante***, esto consistirá en hacer un paso por referencia pero bloqueando que este pueda ser modificado, pues lo determinaremos como una constante.

```cpp
vector<int> my_vector;

int my_function(const vectorr<int>& func_vector) {
	// De este modo aquí func_vector se refiere al espacio
	// de memoria de my_vector pero al ser una constante
	// este no puede ser modificado.
	
	func_vector[0] = 3; // ❌ ERROR de compilación.
}
```

Por el contrario, el ```return``` funciona exactamente igual, simplemente la función retorna un vector.

## Dualidad String - Vector

En el fondo, ```string``` es un vector de ```char```, por lo que un ```string``` puede ser tratado perfectamente del mismo modo que un ```vector<char>```. Pudiendo así recorrer sus caracteres, etc...

