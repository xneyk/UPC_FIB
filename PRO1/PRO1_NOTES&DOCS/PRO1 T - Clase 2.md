#Teoría

Se dice que una expresión es entera cuando su resultado es un entero.
Del mismo modo, se dice que una expresión es **BOOLEANA** cuando su resultado es del tipo de dato ```boolean```.

## Condicionales

Los condicionales evalúan condiciones booleanas (expresiones booleanas) y dependiendo de si son verdaderas (```true```) o falsas (```false```) ejecutara un bloque o otro.

**Ejemplo:** 
```cpp
if(E1) {
	// Si E1 es cierta se ejecuta este bloque...
} else {
	// Si E2 es falsa se ejecuta este bloque...
}
```

En el caso que mi intención fuera realizar más condicionales en el caso de que la primera condición ```E1``` no se cumpla (su resultado sea falso) lo hariamos de la siguiente manera:
```cpp
if(E1) {
	// Si E1 es cierta se ejecuta este bloque...
} else if(E2) {
	// Si E1 es falsa y E2 es cierta se ejecuta este bloque...
} else if(E3) {
	// Si E2 es falsa y E3 es cierta se ejecuta este bloque...
} else if(E4) {
	// Si E3 es falsa y E4 cierta se ejecuta este bloque...
} ...

```

Los condicionales escritos de esta manera se ejecutan de manera secuencial, de modo que tal y como una condición sea cierta, el resto de los condicionales anidados no se evaluarán, es decir, se saltará todos los bloques siguientes y seguirá con el programa.
 
## Jerarquía de Operadores
*Ordenados de mayor a menor preferencia siendo la primera fila la mas prioritaria y la última la menos prioritaria*

*Unary es "Unarios", y se refiere al cambio de signo de una variable. (```-x```) ¡¡¡No se refiere a los operadores de adición!!!*

| Nombre | Operadores | 
|------|------|
| Unary | ```+ - not``` |
| Multiplicative | ```* / %``` |
| Additive | ```+ -``` |
| Relational (inequalities) | ```> >= <= <``` |
| Relational (equalities) | ```== !=``` |
| Conjunction | ```and``` |
| Disjunction | ```or``` |

## Bucles
Cuando queremos que un bloque de código se ejecute repetidamente mientras una condición se cumpla usamos los bucles.
### While
```cpp
while(E1){
	// Bloque de código que debe repetirse
}
```

Mientras (```while```) la expresión ```E1``` sea cierta, el programa entrará al bloque y ejecutará el código de dentro. Una vez llegado a la última línea del bloque (```}```) vuelve al inicio del bucle, comprueba si la condición sigue siendo cierta y vuelve a iterar el bucle. En el momento en el que la condición evaluada retorne falso (```false```) el programa deja de iterar el bucle y sigue con la ejecución normal, línea a línea.

**Ejercicio 1:**
```
# Dado un numero n, escribe los numeros 0, 1, 2 ... n cada uno en una linea
```

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int i = 0; // Indice del iterador, y el número que se va a escribir por pantalla.

	while(i <= n) {
		cout << i << endl;
		++i; // Equivale a i = i + 1;
	}
}
```

**Ejercicio 2:**
```
# Dado un número n, escribe la suma de sus digitos
# Entrada: Número entero NO negativo.
```

```cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	int s = 0;
	cin >> n;

   cout << "La suma de los digitos de " << n << " resulta: ";
	while(n > 0) {
      s = s + (n % 10);
      n = n / 10;
   }
   cout << s << endl;
}
```

### For
Cuando deseo iterar un bloque de código un número fijo de iteraciones (vueltas) no usaremos el bucle ```while```, sino el bucle ```for``` el cual esta específicamente diseñado para ello.

**Estructura de un bucle for:**
```cpp
for(init-expresion; condition; loop-expresion) {
	//CODE
}
```

**```init-expression:```** Inicialización de la variable contador (por convenio solemos llamarle ```i```)
**```conditional-expression:```** Condición que debe cumplirse para ejecutar el bloque.
**```loop-expresion:```** Modificación de la variable ```i``` que será aplicada una vez terminada la ejecución del bloque.

**Ejemplo:** ```Contador desde 0 hasta 99```
```cpp
#include <iostream>
using namespace std;

int main() {
	for(int i = 0; i < 100; ++i){
		cout << i << endl;
		
		//¿Puedo hacer...?
		i = 100; // Para forzar la salida de un bucle for?
		/* NOOO!!! No podemos modificar la var del bucle
		dentro del bucle */
	}
}
```

**Ejercicio 1:**
```# Recive dos numeros x, y e imprime por pantalla su producto. NO se puede usar el operador *```

```cpp
#include <iostream>
using namespace std;

int main() {
	int x, y;
	int r = 0;
	cin >> x >> y;

	for(int i = 0; i < y; ++i) {
		r = r + x;
	}

	cout << r << endl;
}
```

* Podríamos intentar el mismo problema pero para las potencias.