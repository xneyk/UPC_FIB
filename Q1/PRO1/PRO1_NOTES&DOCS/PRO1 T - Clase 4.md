#Teoría 
# Tratamiento de secuencias de secuencias

La entrada es una **secuencia cuyos elementos son a la vez otra secuencia**

**Ejemplo:**
```Input:``` La entrada consiste en un numero n, y n líneas. Cada linea es una secuencia de naturales acabada en ```-1```.
```Output:``` Para cada línea escribir su suma.

Si tengo que sumar todos los elementos de cada secuencia hasta llegar a ```-1```, deberé recorrer todos los elementos, por lo tanto, la estructura seguro que va a ser un recorrido. [PRO1 T - Clase 3](PRO1%20T%20-%20Clase%203.md)

1. En primer lugar, voy a tener que tratar n líneas, por lo tanto:
```cpp
int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		// Tratamos línea i
	}
}
```

2. Tendremos que tratar cada secuencia haciendo un recorrido, con el centinela -1, pues la secuencia acaba cuando x == -1.
```cpp
int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		// Tratamos línea i
		int actual;
		cin >> actual;
		while (actual != -1) {
			// Tratamos cada elemento de la secuencia.
			
			cin >> actual;
		}
	}
}
```

3. ¿Qué información debo recordar de la parte tratada? Si lo que tengo que dar al final es la suma de todos los elementos, seguro que tengo que guardar la suma de los elementos hasta este momento.
4. ¿A que valor inicializo la suma? En un primer momento, no nos habrá llegado ningún elemento a sumar, por lo tanto, seguro que tengo que inicializarla en 0.
```cpp
int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		// Tratamos línea i
		int suma = 0;
		int actual;
		cin >> actual;
		while (actual != -1) {
			// Tratamos cada elemento de la secuencia.
			
			suma += actual;
			cin >> actual;
		}
		cout << suma << endl; 
		// Una vez lleguemos a -1, vamos a imprimir la suma.
	}
}
```

**Ejemplo 2:** 
Imaginemos ahora, que no nos dicen cuantas líneas tenemos, es decir, solamente nos dice que nos van a estar entrando secuencias **acabadas en ```-1```**.

De igual modo, sabemos que cada linea acabará con un ```-1``` por lo tanto, el for que usábamos en el primer ejercicio puede convertirse también en un recorrido.

```cpp
int main() {
	int actual;
	// Sabemos que al menos entra un -1
	while (cin >> actual) {
		int suma = 0;
		while (actual != -1) {
			suma += actual;
			cin >> actual;
		}
		cout << suma << endl;
	}
}
```

El primer ```while()``` va a consumir el primer valor de cada linea, de modo que si este no es ```-1``` el resto de la secuencia hasta encontrar un ```-1``` la va a consumir el ```cin >> actual``` que se encuentra dentro del segundo ```while()```
