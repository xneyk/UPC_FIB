#Teoría 

*La clase de hoy la dedicaremos a seguir con el tipo de dato Vector.*
# Esquemas algorítmicos sobre Vectores

Dado que los vectores son secuencias de valores, podemos aplicar algoritmos, ya sean de recorrido, búsqueda, ordenación, ...

Si en algún momento se nos advierte de que el vector está ordenado es porque podemos aprovechar que este ordenado.

## Recorrido
Los recorridos los podemos realizar tanto de izquierda a derecha como de derecha a izquierda. No obstante, al ser un recorrido, como finalmente acabaremos visitando todas las casillas del vector, es probable que sea irrelevante la dirección.

**En primer lugar, deberíamos saber el tamaño del vector**, por lo que antes de un recorrido seguro que debemos usar un ```v.size()```.

**Ejemplo:**. *Recorremos el vector y imprimimos el valor de cada índice multiplicado por 2*.

```cpp
// v: {5,7,10,4,2,-1}
int n = v.size(); // n = 6
for (int i = 0; i < n; ++i) {
	cout << v[i] * 2;
}
```

## Búsqueda lineal
***Para cuando un vector esta DESORDENADO.***
En una búsqueda ya no es irrelevante ir de izquierda a derecha o de derecha a izquierda, pues estamos buscando un elemento el cual cuando encontremos pararemos la iteración. Por esta razón no es lo mismo avanzar en un sentido o en otro.

**Ejemplo:** *Nos piden encontrar el último elemento del vector que cumple "x". (Se retorna -1 si no existe ningún impar)*

* Si planteamos la búsqueda de izquierda a derecha, tendremos que hacer un recorrido, pues deberé recorrer el vector entero para poder decir que el último es el último.
* Por el contrario, si hago la visita de derecha a izquierda, el último elemento que cumplía la condición se ha convertido en el primero que la cumple, por lo que la búsqueda será extremadamente más corta y eficiente.

```cpp
// Encontrar el último impar.
// v: {5,7,10,4,2,-1}

int last_odd(const vector<int>& v) { //Paso por ref. const.
	int n = v.size() - 1; // último índice del vector
	bool found  = false;
	
	while (not found and 0 <= n) { // 0 --> primer índice
		if (v[n]%2 != 0) {
         found = true;
		   return n;
		}
	    --n;
	}
	return -1;
}
```

## Búsqueda dicotómica:
***Para cuando un vector está ORDENADO***

La idea de la búsqueda dicotómica o binaria es, aprovechando que el vector esta ordenado, ir dividiendo el tamaño de la parte a tratar de modo que eliminamos la mitad a cada vez que consultamos.

A rasgos generales, nos preguntaremos si el elemento que buscamos pertenece a la primera mitad o a la segunda. Si pertenece a la primera, descartaremos la segunda y volveremos a preguntarnos lo mismo.

***¿A que mitad pertenece?***

### ¿Cómo calcularemos el índice que está a la mitad?
$$middle = left + \frac{rigth - left}{2}$$
Que si manipulamos nos queda...
$$middle = \frac{left + right}{2}$$
Dónde ```middle``` es el índice del medio del vector, ```left``` el del primer elemento y ```right```el del último.

### ¿Cómo sabremos si NO hemos encontrado el elemento?
A medida que hacemos consultas, ```left```y ```right```van acercándose cada vez más hasta ser iguales, en caso de no encontrar el elemento estos quedaran cruzados, de modo que ```right > left``` y por tanto, el elemento que buscamos no pertenece a este vector.

**Ejemplo:** *Buscamos x dentro del vector*

```cpp
int busqueda_binaria (const vector<int>& v, int x) {
// ITERATIVA
	int izq = 0;
	int dcha = v.size() − 1;
	
	while (izq <= dcha) {
		int m = (dcha + izq) / 2;
		
		if (v[m] < x) izq = m + 1;
		else if(x < v[m]) dcha = m − 1;
		else return m;
	}
	return −1;
}
```

## Dando significado al indice a los Vectores
**Ejemplo ejercicio:** *Queremos saber si dos palabras son "anagramas"*
*Anagrama:* Dos palabras son anagramas si tienen las mismas letras el mismo número de veces
```Entrada: "ROMA", "AMOR" ........... Salida: Si```

#### Algoritmo:
* Leer la primera secuencia contando cuántas veces aparece cada una de sus letras. **Dónde lo almaceno?**
* Leer la segunda secuencia descontando el número de veces que aparece cada letra. Si en algún punto algún contaje se hace negativo, la frase no es anagrama.
* Comprobar si todos los contadores son 0. Si lo son, es anagrama. Si no, no lo es.

![](Correspondencia_Valor-Indice.png)

**Dónde lo almaceno?** *Los contadores serán casillas* de un vector, de modo que a cada indice le asigno un valor. Esto también es conocido como ```clave-valor```.

```cpp
'a' - 'a' // 0
'b' - 'a' // 1
...
'z' - 'a' // 26

// De este modo cada indice tiene un significado!
// VECES QUE HA APARECIDO LA LETRA cuya 
// distancia a 'a' es i.
```

## Dando significado a los Vectores
Podríamos tratar también un Vector como un polinomio, asignando el valor de cada casilla a los términos ```a,b,c,... y termino independiente``` y asociando el indice al exponente de cada x.

![](Indices_GradoPolinomio.png)

# Typedef

La palabra clave ```typedef``` nos sirve para definir sinónimos. Para casos como el que acabamos de ver, un vector de enteros que representa un polinomio podríamos  indicar que cuando hablemos de ```Polinomio``` nos estamos refiriendo a ```vector<int>```.

```cpp
typedef tipo_de_datos_existente nuevo_nombre;

//otra sintaxis: compilar con −std=c++11 o superior
using nuevo_nombre = tipo_de_datos_existente;
```

**Ejemplo:**
```cpp
typedef vector<int> Polinomy;
```

# Algoritmos de ordenación con la librería ```algorithm```.

```#include <algorithm>```

### Ordenación ascendente.
Para ordenar un vector de menor a mayor, usaremos la función ```sort()```. Esta puede ser usada en cualquier tipo de datos que tenga definido el operador ```<```.

Esto lo haremos del siguiente modo:

```cpp
// v: {5,7,10,4,2,-1}
sort(v.begin(), v.end()) // {-1,2,4,5,7,10}
```

## Ordenación para otros casos.
Para cualquier otro caso, también usaremos el algoritmo ```size()```, no obstante, esta vez deberemos  pasarle un tercer parámetro de tipo ```bool function```.

Esta función ```boleana``` indica con que criterio un elemento va antes que otro. De una forma más correcta, cuando un elemento **es mejor** que otro. 

*Internamente el algoritmo ```sort()``` compara por parejas de elementos, por lo que si queremos que siga un criterio distinto al ```<``` debemos indicarle con que criterio **a** va antes que **b**.*

**Sintaxis:**
```cpp
sort(vector.begin(), vector.end(), boolean_function);
```

**Ejemplo:** *Ordenar un vector en orden decreciente **no** estricto.*
```cpp
// my_numbers: {5,7,10,4,7,2,-1}
// Post: retorna true si a tiene que ir antes que b en el vector.
bool better(int a, int b) {
// a i b mateix data_type que els elements del vector
	if (a >= b) return true;
	else return false;
}

sort(my_numbers.begin(), my_numbers.end(), better);
// {10,7,7,5,4,2,-1}
```
