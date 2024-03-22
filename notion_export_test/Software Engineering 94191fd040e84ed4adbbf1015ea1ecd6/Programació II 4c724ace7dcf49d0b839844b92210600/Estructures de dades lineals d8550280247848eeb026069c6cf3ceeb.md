# Estructures de dades lineals

En esta clase vamos a estar viendo dos de las tres estructuras lineales de este curso, Pilas (o *Stack*) y Colas (o *Queue*).

## Tipos de Datos Abstrucato (ADT)

- Abstración: Consiste en reducir un sistema complejo de sus partes fundamentales

**ADT** Un modelo matemático de una estructura de datos que especifica:

- El tipo de dato que almacena
- Las operaciones que proporciona: Concretamente especifica qu ́e
hace cada operaci ́on, pero no c ́omo lo hace.
- Los tipos de los parámetros de las operaciones

En general, nos referiremos al comportamiento global de las opera- ciones proporcionadas por un ADT como a su especificaci ́on o a su interfaz pu ́blico.

# Stack

Una pila *(En C++ Stack)* es una colección de objetos que se insertan y extraen siguiendo la regla **LIFO** (*last-in-first-out*).

> Stack es una clase de C++, por lo que de querer usarla deberemos importarla de igual modo a como hacemos con la clase vector, string, etc.
> 

```cpp
#include <iostream>
#include <stack> // <--- Importamos.
```

### .push()

El método `Stack.push()` inserta un elemento a la pila, es decir, lo añade arriba del todo de la pila.

> Coste constante
> 

### .pop()

El método `Stack.pop()` extrae/elimina el primer elemento de la pila *(El de arriba del todo)*

> Coste constante
> 

### .top()

- *Coste constante*
El método `Stack.top()` retorna el primer elemento de la pila, es decir, nos deja ver cuál es el elemento que se encuentra actualmente arriba del todo de la pila.

> Coste constante
> 

## Especificació formal de la pila.

```
template <class T> class stack{
// Tipus de mòdul: dades
// Descripció del tipus: Estructura lineal que conté elements de tipus T i que permet consultar i eliminar només l’últim element afegit

private:

public:
// Constructores

stack();
/* Pre: cert */
/* Post: El resultat és una pila sense cap element */

stack(const stack<T>& original);
/* Pre: cert */
/* Post: El resultat és una còpia d’original */
// Modificadores

void push(const T& x);
/* Pre: cert */
/* Post: El paràmetre implícit és com el paràmetre implícit original amb x afegit com a darrer element */

void pop();
/* Pre: El paràmetre implícit no està buit */
/* Post: El paràmetre implícit és com el paràmetre implícit original però sense el darrer element afegit al paràmetre implícit original */

// Consultores
T top() const;
/* Pre: El paràmetre implícit no està buit */
/* Post: El resultat és el darrer valor afegit al paràmetre implícit */

bool empty() const;
/* Pre: cert */
/* Post: El resultat indica si el paràmetre implícit és buit o no */

int size() const;
/* Pre: cert */
/* Post: El resultat és el nombre d’elements del paràmetre implícit */
};

```

## Sintaxi

Como bien hemos visto arriba, en la especificación formal ADT Stack, las pilas tienen tipado, de igualmanera que lo tiene un vector, por lo tanto al momento de declarar una pila, deberemos declarar que tipo de dato van a tener sus elementos.

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s; //Declaramos la pila y se inicializa vacia.

	s.push(1); // s = {1}
	s.push(2); // s = {2,1}
	s.push(3); // s = {3,2,1}
	s.push(4); // s = {4,3,2,1}

	int actual_top = s.top(); // Retorna 4

	s.push(); // s = {3,2,1}
}

```

### ¿Cómo puedo escribir/imprimir una pila?

Como bien hemos dicho al inicio, en una pila solamente nos es accesible el elemento de arriba de la pila, por lo que si queremos mostrar el contenido de la pila deberemos hacer una copia e ir haciendo `.pop()`hasta haber vaciado la copia.

```cpp
void print_stack(stack<T> s) { //Siendo T el tipo de la pila.
	while (not s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
}

```

# Cola

Una cola (*En C++ Queue*) es una coleccion de objetos que se insertan y extraen siguendo la regla FIFO, (first-in-first-out).

Cabe aclarar que de igual modo a la pila, en la cola solo tenemos un elemento accesible, en este caso, el primero de la cola (o frente de la cola.)

### Especificación formal (pública) de la cola C++

```
template <class T> class queue{
// Tipus de mòdul: dades
// Descripció del tipus: Estructura lineal que conté elements de tipus T i que
// permet consultar i eliminar només el primer element afegit

private:

public:

// Constructores

queue();
/* Pre: cert */
/* Post: El resultat és una cua sense cap element */

queue(const queue &original);
/* Pre: cert */
/* Post: El resultat és una cua còpia d’original */

// Modificadores

void push(const T& x);
/* Pre: cert */
/* Post: El paràmetre implícit és com el paràmetre implícit original amb x afegit com a darrer element */

void pop();
/* Pre: El paràmetre implícit no està buit */
/* Post: El paràmetre implícit és com el paràmetre implícit original però sense el primer element afegit al paràmetre implícit original */

// Consultores

T front() const;
/* Pre: El paràmetre implícit no està buit */
/* Post: El resultat és el valor més antic afegit al paràmetre implícit */

bool empty() const;
/* Pre: cert */
/* Post: El resultat indica si el paràmetre implícit és buit o no */

int size() const;
/* Pre: cert */
/* Post: El resultat és el nombre d’elements del paràmetre implícit */
};

```

# Listas

Una lista es una estrutura de datos lineales que contiene elementos de tipo `T`, que se pasa como parametro a su constructor como en el caso de la classe vector.

```
list<T> list_name; // Lista de elementos tipo T vacia

```

- El acceso a los elementos de una lista se hace mediante ***iteradores***.
- **Iterador:** Contiene la dirección de un elemento de una lista en la memoria y permite su uso de forma controlada.

```
list<string>::iterator it; // Iterador de list<string>

list<string>::const_iterator itc; // Iterador constante de list<string>

```

- El iterador `it` permite acceder a elementos de cualquier lista de `string`.
- El iterador `itc` permite consultar elementos de cualquier lista de `string` pero no modificarlos.

*Cuidado: Un iterador NO es un puntero, esta implementado on un puntero pero restringe su uso a una manera controlada*

La definición de la clase `iterador` esta definida dentro de la clase lista, de ahi la sintaxi de los dos puntos `::`.

## ¿Como estan estructuradas las listas?

Las listas estan formadas por nodos doblemente enlazados.

![https://www.notion.soPasted%20image%2020240305162133.png](https://www.notion.soPasted%20image%2020240305162133.png)

`.begin()` devuelve el primer elemento de la lista
`.end()` devuelve el ultimo elemento de la lista, que es `null`, por lo que para apuntar al ultimo elemento real de la lista deberiamos hacer:

```cpp
it = l.end();
--it;

```

![https://www.notion.soPasted%20image%2020240305162311.png](https://www.notion.soPasted%20image%2020240305162311.png)

### Operador de dereferencia ``

El operador `*` nos devuelve el contenido de la dirección de memoria a la que apunta el iterador. Es decir, si tenemos el iterador apuntando a nuestro quinto elemento de la lista el cual és 5425, `*it` nos devolvera el valor 5425.

### Recorrido en una lista

```cpp
for (it = l.begin(); it != l.end(); ++it) {
	cout << ' ' << *it;
}
cout << endl;

```

**Abreviatura ->**
Imaginemos que tenemos una lista de structs con un iterador apuntando a un elemento de tipo struct. imaginemos que quiero acceder a la propiedad `.peso`del struct `Persona` de dentro de la lista.
`(*it).peso` esta expresión es equivalente hacer `it->peso`

### Insert, Erase

El método `l.erase(iterator_name)` elimina el elemento de la dirección `it` y devuelve:

- La posición del siguiente nodo de la lista
- la posición de `l.end()`en caso de que la lista sea vacia
Por esto mismo, cuando hagamos un `l.erase(iterator_name)` nos interesará reasignar nuestro iterador a lo que devuelve el método.
**Ejemplo:** `it = l.erase(it)`

> Cuidado en caso de no hacerlo, it seguirá apuntado a la dirección del elemento borrado, la cual ya NO es una posición válida.
> 

### push_front, push_back

Ambos dos métodos hacen lo que cualquiera esperaria...

- `l.push_front()` añade un elemento al inicio de la lista
- `l.push_back()`añade un elemento al final de la lista
*Ambas operaciónes en tiempo lineal, e aquí la "gracia" de usar listas*

```
template <class T> class list {
// Tipus de mòdul : dades
// Descripció del tipus: Estructura lineal que conté elements de tipus T, que es pot començar a consultar pels extrems, on des de cada element es pot accedir a l’element anterior i posterior (si existeixen), i que admet afegir-hi i esborrar-hi elements a qualsevol punt

private:

public:

// Constructores

list();
/* Pre: cert */
/* Post: El resultat és una llista sense cap element */

list(const list & original);
/* Pre: cert */
/* Post: El resultat és una llista còpia d’original */

// Modificadores

void clear();
/* Pre: cert */
/* Post: El paràmetre implícit és una llista buida */

void insert(iterator it, const T& x);
/* Pre: it referencia algun element existent al paràmetre implícit o és igual a l’end() d’aquest */
/* Post: El paràmetre implícit és com el paràmetre implícit original amb x davant de l’element referenciat per it al paràmetre implícit original */

iterator erase(iterator it);
/* Pre: it referencia algun element existent al paràmetre implícit, que no és buit */
/* Post: El paràmetre implícit és com el paràmetre implícit original sense l’element referenciat per l’it original; el resultat referencia l’element següent al que referenciava it al paràmetre implícit original */

void splice(iterator it, list& l);
/* Pre: l=L, it referencia algun element del paràmetre implícit o és igual a l’end() d’aquest; el p.i. i l no són el mateix objecte */
/* Post: El paràmetre implícit té els seus elements originals i els d’l inserits davant de l’element referenciat per it; l està buida */

// Consultores

bool empty() const;
/* Pre: cert */
/* Post: El resultat indica si el paràmetre implícit té elements o no */

int size() const;
/* Pre: cert */
/* Post: El resultat és el nombre d’elements del paràmetre implícit */
};

```

# Conjuntos y Diccionarios

Un conjunto `<set>` representa un conjunto de elementos
Un diccionario `<map>` representa un conjunto de pares de forma **(clave, valor)**. Asi entonces, un diccionario es asociativo, por lo que no va a poder pasar que existan dos pares `(k, valor1) y (k,valor2)`tal que `valor1 != valor2`

## Conjunto ordenado

Un conjunto ordenado `<set>` representa un conjunto de elementos
¿Que podemos hacer?

- Añadir/eliminar un elemento (sin repeticion)
- Comprobar si el conjunto tiene un elemento
- Tamaño del conjunto
- Comprobar si el conjunto es vacio
- Recorrer los elementos del conjunto en orden creciente

## Diccionario ordenado

Un diccionario ordenado `<map>` representa un conjunto de pares de la forma `(clave, valor)`
¿Que podemos hacer?

- Añadir un par
- Eliminar un par **a partir de la clave de ese par**
- Comprobar si el dicionario contiene un par **con una determinada clave**
- Consultar el valor associado **a una clave determinada**
- Modificar el valor associado **a una clave determinada**
- Comprobar si el diccionario esta vacio
- Recorrer los pares `(clave, valor)` en orden creciente **de clave***Los pares se representan mediante la estructura de datos `pair<T1,T2>`*, donde `T1` es el tipo de la clave y `T2` el tipo del valor.

### ¿Como se implementan por dentro?

Los diccionarios y los sets estan implementados con arboles binarios de busqueda equilibrados, de modo que la profundidad (o altura) del arbol es log(n).

# Sobre carga de operadores en C++

En algunas ocasiones es útil redefinir los operadores tales como `<` para la comparar tipos de elementos en los que no están definidos.

```cpp
bool operador<(param a, param b) {
	// especificación de que hace determina a < b cierto
}

ostream &operator<<(ostream &os, const Person p) {
	os << ...
}
```

`ostream &operator<<` retorna la referencia al teclat/document (no podem retornar una copia del teclat ja que es un element físic) recive como parametros `ostream &os`, el cual es una referencia a un objeto outstream, en este caso la pantalla cuando lo usemos con `cout` y `const Person p` que es un elemento del tipo de dato al que queremos sobrecargarle el operador de escritura `<<`. El operador debe retornar un `ostream` para poder encadenarlos uno detras de otro como bien estamos acostrumbrados: `cout << a << b << c;`