# Algoritmos Fundamentales
Esta clase la vamos a dedicar a conocer algunos algoritmos fundamentales a partir de algunos ejercicios de ejemplo.

## Criba de Eratóstenes
**Input:** Una secuencia de naturales x1, x2, ... , xn.
* Donde n es muy grande (Una secuencia muy larga)
* 1 <= xi <= M (siendo M un valor relativamente pequeño)
*(Una secuencia muy larga de números pequeños)*
**Output:** Por cada elemento de la secuencia, escribir "SI" si el elemento es primo y "NO" en caso contrario.

Hasta ahora, lo podríamos hacer, planteando un recorrido y calculando para cada xi si es primo o no. Esto esta bien, pero **es muy lento y no hemos usado ninguna de las pistas que nos dan**.

>Podríamos plantearlo del siguiente modo:
>Calcularemos desde 1 hasta M si son primos o no, y nos acordaremos cuales son primos y cuales no. Cuando nos pregunten dos o mas veces por el mismo numero ya lo tendremos calculado, por lo que no tendremos que calcularlo de nuevo.

La primera idea que podríamos pensar seria almacenar si el numero es primo o no en un vector donde el indice corresponda al numero y los elementos sean de tipo bool. (```true``` / ```false```).

Esto ya ha mejorado mucho, no obstante, Eratóstenes ideo un algoritmo aún mas eficiente.

**Idea general:** Si n es primo, todos los múltiplos de n no serán primos. 
Con esta idea, haremos un listado desde 0 hasta M asumiendo que todos son primos, una vez tengamos esto, vemos si el primer elemento es primo, cada vez que el elemento sea primo, tacho todos sus múltiplos hasta llegar a M. A continuación, busco el siguiente numero que no este tachado y repito el proceso.

```cpp
vector<bool> cribaEratostenes(int m) {
	vector<bool> v(m+1, true);
	v[0] = v[1] = false; // 0 y 1 no son primos.
	for (int i = 2; i <= m; ++i) {
		if(v[i]) { // "si no esta tachado"
			for (int j = 2*i; j <= m; j = j + i) {
			// Desde el primer multiplo de i no tachado
			// Tacho los multiplos de i.
				v[j] = false;
			}
		}
	}
	return v;
}
```

*Añadamos ahora algunas mejoras...*

```cpp
vector<bool> cribaEratostenes(int m) {
	vector<bool> v(m+1, true);
	v[0] = v[1] = false; // 0 y 1 no son primos.
	for (int i = 2; i*i <= m; ++i) {
		//El bucle interno solo hara hasta i*i <= m, por lo que todas
		//las demas iteraciones del bucle de fuera no hacen nada.
		if(v[i]) { // "si no esta tachado"
			for (int j = i*i; j <= m; j = j + i) {
			// i*i es el primer multiplo no tachado hasta el momento.
				v[j] = false;
			}
		}
	}
	return v;
}
```

* ```i*i``` es el primer múltiplo no tachado hasta el momento.
	* Pongamos un ejemplo para los múltiplos de 5:
	* 5 * 2 = 10 *múltiplo de 2*
	* 5 * 3 = 15 *múltiplo de 3*
	* 5 * 4 = 20 *múltiplo de 4*
	* 5 * 5 = 25 *primer múltiplo no tachado!*

Volvamos entonces a nuestro ejercicio:

**Input:** Una secuencia de naturales x1, x2, ... , xn.
* Donde n es muy grande (Una secuencia muy larga)
* 1 <= xi <= M (siendo M un valor relativamente pequeño)
*(Una secuencia muy larga de números pequeños)*
**Output:** Por cada elemento de la secuencia, escribir "SI" si el elemento es primo y "NO" en caso contrario.

```cpp
vector<bool> cribaEratostenes(int m) {
	vector<bool> v(m+1, true);
	v[0] = v[1] = false;
	for (int i = 2; i*i <= m; ++i) {
		if(v[i]) {
			for (int j = i*i; j <= m; j = j + i) {
				v[j] = false;
			}
		}
	}
	return v;
}

int main() {
	const int M = ?? // La que nos digan
	vector<bool> p = cribaEratostenes(M);
	
	while (cin >> x) {
		if(p[x]) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
}
```

## Rios digitales
Un rio digital de un numero N es la secuencia desde N  hasta infinito donde el siguiente elemento se calcula según la suma de Ni-1 + la suma de los dígitos de Ni-1.
**Ejemplo:** Rio digital de 50:
- 50, 55, 65, 76, ...  *(76 es 65 + 6 + 5)*

**Nos dicen que esta matemáticamente demostrado que dado el rio de M, siempre interseccióna con el rio de 1, de 3 o de 9**

**Ejercicio:** Decir cual es la primera intersección entre el rio de M con alguno de los otros tres.

>Sabemos como avanza la secuencia y sabemos que siempre es **estrictamente ascendientes**

De este modo podemos plantearlo de igual modo al que vimos en clases anteriores, con el símil de los dos montones de cartas e ir descartando.

# Algoritmos de ordenación
En esta clase vamos a empezar a ver aquellos algoritmos de ordenación fundamentales para todo programador, en la siguiente seguiremos viendo los demás .

## Sort, ¿cómo esta implementado?
Dividiremos la parte tratada de dos maneras
1. Ordenada *(Si solo miramos la parte tratada, esta ordenado)*
2. Correctamente ordenada *(Los elementos están en la casilla que les toca)*
![](Dif_Ordenada-CorrectamenteOrd.png)

## Algoritmo de selección
Hacemos un recorrido por todas las casillas e intercambiamos el valor de la casilla iésima con el valor de la casilla con el mínimo desde la posición ```i``` hasta el final. De este modo, la parte tratada siempre estará correctamente ordenada y la parte por tratar desordenada

```cpp
void swap(int& a, int&b) {
	int aux = a;
	a = b;
	b = aux;
}

int pos_min(const vector<int>& v, int from) {
	int p = from; //Como mínimo el mínimo esta en i inicial.
	int lenght = v.size();
	for (int i = from + 1; i < lenght; ++i) {
		// AQUI ES DONDE DEFINIMOS LA RELACION A mejor que B.
		if (v[i] < v[p]) p = i;
	}
	return p;
}

void sort_selection(vector<int>& v) {
	lenght = v.size():
	for (int i = 0; i < lenght; ++i) {
		int p_min = pos_min(v, i);
		swap(v[i],v[p_min]);
	}
}
```

Viendo donde es que definimos la relación A mejor que B, podemos encapsularla, haciendo que podamos reutilizar el algoritmo definiendo en cada caso solamente con que criterio A va antes que B.

```cpp
bool a_better_b(int& a, int& b) {
	return v[i] >= v[p]; // Ahora ordena de mayor a menor no estricto.
}

void swap(int& a, int&b) {
	int aux = a;
	a = b;
	b = aux;
}

int pos_min(const vector<int>& v, int from) {
	int p = from; //Como mínimo el mínimo esta en i inicial.
	int lenght = v.size();
	for (int i = from + 1; i < lenght; ++i) {
		// AQUI ES DONDE DEFINIMOS LA RELACION A mejor que B.
		if (a_better_b(v[i],v[p)]) p = i;
	}
	return p;
}

void sort_selection(vector<int>& v) {
	lenght = v.size():
	for (int i = 0; i < lenght; ++i) {
		int p_min = pos_min(v, i);
		swap(v[i],v[p_min]);
	}
}
```

## Algoritmo de inserción
Nuestra parte tratada estará **ordenada** pero NO correctamente ordenada.
Cuando tratemos un nuevo elemento, buscaremos en que posición **de la parte tratada** debería estar.

```cpp
void sort_insert(vector<int>& v) {
	int n = v.size();
	for (int i = 1; i < n; ++i) {
	// Busca la posicion correcta para v[i] desde i hasta 0
	int x = v[i];
	int j = i; // Posible posicion a la que ir.
	while (j > 0 and v[j - 1] > x) { // AQUI DEFINIMOS LA CONDICIÓN
		v[j] = v[j-1];
		--j;
	}
	// Al salir del bucle, j es la posición que buscábamos.
	v[j] = x;
}
```

