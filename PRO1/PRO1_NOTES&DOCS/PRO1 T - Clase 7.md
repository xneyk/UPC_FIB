#Teoría 
# Recursividad
Recursividad es la forma en la que se especifica un proceso basado en su propia definición. Es decir, una definición recursiva es aquella en la que en su propia definición aparece el mismo.

**Principio:** Reducir un problema complejo en una instancia mas sencilla del mismo problema.

*Un ejemplo de este principio es las famosas matrioshkas.*

**Esquema de una función recursiva:**
```cpp
data_type func() {
	// Code...
	func();
}
```

**Esquema de un proceso (acción) recursivo:**
```cpp
void proc() {
	// Code...
	proc();
}
```

## Características de una definición recursiva.
Las características de una definición recursiva que nos indica que esta es correcta son:
1. Uno o más casos base
2. Uno o mas casos recursivos.
	1. Debe ser distinto del caso base. *(Ejemplo para el factorial: El caso base es n! y en el recursivo tengo (n-1)!)*
	2. Cada vez debe acercarse al caso base, es decir, que si hago las suficientes llamadas recursivas en cascada siempre debo llegar al caso base.

## Factorial de un numero de forma recursiva:
```cpp
#include <iostream>
using namespace std;

int factorial(int n){
	if(n == 0) return 1;
	else return n * factorial(n - 1);
}

int main(){
	int x;
	cin >> x;
	
	cout << factorial(x) << endl;
}
```

## ¿Como es la ejecución de una función recursiva?

![](RecursivelyExeOutline_TClass7.png)
A nivel interno, como bien se explicó en [PRO1 T - Clase 6](PRO1%20T%20-%20Clase%206.md), cuando la ejecución del programa llega a una llamada de una función debe evaluar la función en esa llamada, es decir, averiguar cúal es su valor.

De este modo, ejecuta el código de la función, Una vez dentro del código de la función vuelve a aparecer otra llamada a la función, por lo que debe averiguar nuevamente su valor evaluado en esa llamada.

>*Conclusión: El código anterior a la llamada de la función se ejecuta en el camino de ida, el código posterior a la llamada se ejecuta en el de vuelta.*

**¡Especial atención!**
* Si nunca llega a un caso base entra en un bucle infinito, por lo que en algún momento te vas a quedar sin memoria. **ERROR: Segmentation fault**

### Ejercicio:
Contar el numero de dígitos de un numero de manera recursiva.

1. **Caso base:** cuando n <= 9 (valores representables con un solo dígito) entonces el numero de dígitos es 1.
2. **Caso recursivo:** 1 + numero de dígitos de num/10

```cpp
#include <iostream>
using namespace std;

int ndigits(int n);

int main(){
   int x;
   cin >> x;
   cout << ndigits(x) << endl;
}

int ndigits(int n){
   if(n <= 9) return 1;
   else return 1 + ndigits(n/10);
}
```
