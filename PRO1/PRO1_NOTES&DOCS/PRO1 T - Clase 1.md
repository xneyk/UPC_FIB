#Teoría
# 0. Objetivo y Presentación
El objetivo de este curso es escribir programas informáticos en el lenguaje de programación C++. Estos correrán en sistema operativo Linux.

**Programa informático:** Conjunto de instrucciones que permite al ordenador realizar tareas como sumar dos números, tratar textos, resolver problemas matemáticos, etc.

**Clases de teoria:** 
* 2h semanales
* 13 sesiones
**Clases de Laboratorio:**
* 3h semanales
* 13 sesiones

## Evaluación
**2 Examenes:**
* Parcial: 02/11/2023 (P)
* Final: 15/01/2024 (F)

**Entrega problemas:**
* Entregas semanales, se anunciarán (E)

**Para calcular tu nota final:**
	0.85 * max{ 0.4 * P + 0.6 * F } + 0.15 * E

# 1. Conceptos Básicos
**Algoritmo:** Descripción precisa de como pasar de una situación inicial a una situación final. Es el método de resolución de un problema.
* Los pasos que sigues son las instrucciones, el conjunto el algoritmo.
**Lenguaje de programación:** Lenguaje formal capaz de expresar de forma precisa algoritmos que puedan interpretar máquinas como una computadora. 
**Programa informático:** Algoritmo escrito en un lenguaje de programación que realiza una cierta tarea.
## Plantilla de Programación

Un programa de C++ seguirá la plantilla:
```cpp
#include <iostream>
using namespace std;

int main(){
	...; // Conjunto de instrucciones
	...; // que se ejecutan sequencialmente
	...; // y en orden (de primera a última)
}
```
## Comentarios en código

Para comentarios de una línea usaremos ```//```. Todo lo que haya a partir de las dos barras hasta terminar la línea será ignorado por el compilador.

## Función main()

Todo lenguaje de programación tiene un programa principal. Este es el punto de partida/origen del programa. En C++, el programa principal es la función main().

## Ejercicio 1

```
Dado un numero de segundos n, diga cuantas horas, minutos y segundos represeta.

Entrada: Segundos n

Salida:
	horas: h
	minutos: m
	segundos: s
```

Todos los ejercicios seguiran la estructura:
**Entrada** --> [Algoritmo] --> Salida

**Resolución:**
```cpp
#include <iostream>
using namespace std;

int main(){
int n; // Siendo n un numero natural expresado en segundos (Entrada)
int h, m, s;

cin >> n;

h = n / 3600; //Paquetes de 3600 segundos serán las horas
m = (n % 60) / 60; // Todos los segundos de los que no pueda hacer paquetes de hora serán minutos
s = n % 60; // Todo lo que sobre de paquetes de 60 (minutos) seràn segundos.

cout << h << m << s << endl;

}
```

## Tipos de Datos
Para especificar el tipo de dato de una variable, lo haremos de la siguiente manera:

```cpp 
// palabraClaveParaElTipo nombreDeLaVariable;
int n; // int --> Integer, nombre entero.
```

*! Cabe recordar que en C++, si tienes dos enteros y su división es decimal, el resultado será la parte entera de esa división*

```cpp
int resultado = 5/2; // ❌ 2.5 | ✅ 2
```

El operador ```/```en C++ representa:
* División entera: cuando los operandos son enteros.
* División decimal: cuando alguno de los dos es de tipo ```double```
### Listado de tipos de datos

* **Integer:** Números enteros. Su palabra clave es ```ìnt```
* **Double:** Números decimales. Su palabra clave es ```double```
* **Boolean:** Verdadero o Falso. Su palabra clave es ```bool```
* **Carácter:** UN solo carácter, se escriben entre comillas simples ```''```. Su palabra clave es ```char```. 
	* Ejemplo: ```'a', 'b', ... '8', '9'```
* **String:** Cadena de texto, se escribe entre comillas dobles. Su palabra clave es ```string```

## Variables
Cabe diferenciar entre declarar e inicializar.

```cpp
int n; // la variable n está declarada, pero no inicializada.
```

En este caso, el ordenador ha guardado un espacio en memoria para una variable tipo ```ìnt``` pero no su valor.

```cpp
int n; // la variable n está declarada, pero no inicializada.
n = 13; // Aquí si esta inicializada, ya tiene un valor.
```

## Entradas y Salidas
Usamos ```cin``` para las entradas y ```cout```para las salidas.
*La palabra reservada ```endl``` sirve para decir que acaba la linea, "end line"*

```cpp
#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	cout << "El numero entrat ha estat: " << a << endl;
}
```

## Ejercicio 2

```
Dados dos numeros enteros, devuelva el mínimo/menor de estos dos.
	- a, b (Entrada)
	- r (Salida)
```

```cpp
#include <iostream>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;

	if(a>=b){
		cout << b << endl;
	} else {
		cout << a << endl;
	}
}
```