#Teoría 
# Vectores Multidimensionales
Un vector multidimensional es un vector cuyos elementos son, a la vez, un
vector.

Un ejemplo de esto podría ser una matriz de dos dimensiones, es decir, un vector, cuyas casillas son vectores, cuyas casillas son enteros.

```cpp
vector <vector <int>>
//  |      |
//  |      |-> Segunda dimension (o vector interno)
//  |-> Primera dimension (o vector externo)
//
//  Ejemplo gráfico:
//  {
//	{1,2,3}, Fila 0
//	{4,5,6}  Fila 1
//  }
```

El mismo modo podríamos tener un vector de tres dimensiones.

```cpp
vector <vector <vector <int>>>
// |       |       |-> Tercera dimension
// |       |-> Segunda dimension
// |-> Primera dimension
```

## Representación gráfica de un Vector Multidimensional
Para representar un Vector Multidimensional de forma gráfica y no confundirnos, representaremos el vector externo en vertical e indicaremos con una flechita discontinua que vector contiene esa casilla.

![](Rep.Grafica_VectorMulti.png)

## Declaración de una Matriz
Ya hemos visto que hay diversas maneras de declarar un vector, por lo que tendremos también diversas maneras de declarar matrices...

![](Declaracion_Matrices.png)

Como podemos ver es muy engorroso declararlas de este modo, no obstante, tenemos una mejor opción que simplifica mucho las cosas.

## Declaración simplificada usando Typedef
Como vimos en la clase [anterior](PRO1%20T%20-%20Clase%209.md), podemos usar ```Typedef```para definir sinónimos. Por lo tanto podemos usar un sinonimo para el tipo de datos de una fila (vector) y un sinonimo para la matriz (vector de filas).

```cpp
Typedef vector<int> Row; // Definimos el tipo FILA
Typedef vector<Row> Matrix; // Definimos el tipo MATRIZ
```

De este modo, si queremos declarar una matriz 4 x 3 (4 filas y 3 columnas) podríamos hacerlo como se indica a continuación.

```cpp
Matrix mat(4, Row(3));
```

## Acceso a los indices de la matriz
Como siempre, se va a acceder por el indice de cada vector, por lo tanto, accederemos con una sintaxis parecida a la siguiente:
```cpp
nombre_matriz[E1][E2]
```

* E1 corresponde al indice de la matriz externa
* E2 corresponde al indice de la matriz interna

![](Indices_Matriz.png)

Por lo tanto, si queremos saber cuantas filas tiene nuestra matriz podemos consultar el tamaño del vector externo.
```cpp
int n_rows = mat.size();
```

Del mismo modo, si quisiéramos saber cuantos elementos tiene algún vector interno lo podríamos haciendo accediendo al índice en el que se encuentra almacenado y consultado su tamaño.

**Ejemplo: *El vector almacenado en el indice 1 del vector externo***
```cpp
int row_size = mat[1].size();
// mat[1] --> Es un Vector!
```

>**Si nos dicen que la matriz es rectangular significará que todas las filas tienen el mismo numero de elementos, por lo que podemos hablar de filas y columnas, y no hace falta que consultemos el tamaño de cada fila antes de recorrerla, pues nos basta con consultarla una vez.**

## Escritura y Lectura de una matriz irregular

En primer lugar nos dan un entero que son número de filas **f** . A continuación nos dan f líneas, cada una empieza con un numero **c** que es el número de columnas de esa fila y, a continuación , **c** enteros que son los elementos de esa fila.

```cpp
int main() {
	int f;
	cin >> f;
	
	vector <vector <int>> mat(f); //Vector con f filas.
	
	for(int i = 0; i < f; ++i) { // Recorremos las filas
		int c;
		// Consumimos el numero de columnas de esa fila
		cin >> c;
		mat[i] = vector<int>(c); /* vector sin nombre de
								tamaño c */
		for(int j = 0; j < c; ++j){
			// Asignamos todos los elementos de la fila
			cin >> mat[i][j];
		}
	}
}
```

Imaginemos ahora que queremos leer toda la matriz y ir imprimiendo cada elemento de la matriz.

```cpp
// f = mat.size(); 
for (int i = 0; i < f; ++i) {
	c = mat[i].size(); // Consultamos el tamaño de la fila.
	for(int j = 0; j < c; ++j) {
		cout >> mat[i][j] >> ' ';
	}
	cout >> endl;
}
```

En este código podemos ver un acceso por fila, es decir, recorro toda la fila y una vez he acabado voy a la siguiente fila.

*También podríamos plantear el mismo recorrido pero por columnas.*