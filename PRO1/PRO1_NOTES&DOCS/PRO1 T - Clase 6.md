#Teoría 
# Funciones y Acciones

En esta clase aprenderemos a *encapsular* código. Es decir, le pondremos nombre a un trocito de código que realiza una pequeña tasca. De este modo, entenderemos mejor que hace cada parte del código, y, también, haremos posible re-aprovecharlo.

## Elementos clave a definir en todo encapsulado

0. Precondición / Postcondición:
	- Pre: Situación inicial (que se debe cumplir antes de entrar al fragmento de código)
	- Post: Situación final.
1. Darle un nombre (Si cuesta mucho encontrar un nombre para ese trozo de código puede ser un indicativo de que no se debe encapsular).
2. Identificar las variables (**parámetros**) relevantes.
	* Parámetros de entrada: Su valor lo necesitamos para hacer la tarea
	* Parámetros de salida : Su valor es resultado de la tarea.
	* Parámetros de entrada / salida: Su valor lo necesitamos para hacer la tarea y, además, es también uno de sus resultados. Es decir, son los **mismos parámetros** que entraron en la entrada pero **su valor ha cambiado**.

**Ejemplo:**

```Queremos encapsular un fragmento de codigo que nos calcule el máximo de dos numeros enteros.```
* **Nombre:** Tiene sentido llamarle ```max``` o ```max2```.
* Pre: x, y son enteros
* Post: z es el máximo de x e y

## Función

Es la forma de encapsular cuando calculamos un único valor. Generalmente,
identificamos que la tarea tiene:
* 1 parámetro de salida (es el valor que calculamos y devolvemos).
* 0 o más parámetros de entrada.

#### Semantica de una función:

* Los parámetros de entrada tienen un valor válido (Es decir, supondremos que los datos cumplen la precondición).
	--> Se les da valor en la llamada a esa función.
* Se ejecutan las instrucciones I1, ..., In de manera secuencial y en orden.
* Al encontrar la instrucción return se evalúa ```Expresión``` (cuyo valor
será de tipo tipo_de_datos y es el resultado de la tarea) y se acaba la
ejecución de la función.

#### Sintaxis de una función:
```cpp
data_type function_name (input_params_list) {
	I1;
	...
	In;
	
	return expresion;
	// Lo que haya a partir del return no se va a ejecutar.
}
```

*La cabecera de la función es este primer fragmento que aparece a continuación:*
```cpp
data_type function_name (input_params_list)
```

La manera en la que indicaremos la lista de parámetros de entrada, ```input_params_list```, será la siguiente:

**Ejemplo:** *(Tanto x, como y son del tipo de dato int)*
```cpp
data_type function_name (int x, int y) {
	...
}
```

Vamos a ver un ejemplo de función la cual nos calcule el valor máximo de dos números enteros.

```cpp
int max2(int x, int y) {
	if (x > y) return x;
	return y;
}
```

*Como hemos visto antes, el valor que se retorna tiene que ser del mismo tipo de dato que la función, es decir, del mismo tipo de dato que aparece delante del nombre de la variable. En este caso el tipo de dato es ```int```*.

**¡IMPORTANTE!**
Una función, **siempre** debe tener un return. Si alguna de las posibles ramas de nuestro código llega a un final sin return tendremos un error de compilación.

**Ejemplo:** *Esta es una función con error de compilación que, aparentemente, no llega a ninguna rama sin return.*

```cpp
int max2_incorrecto (int x, int y) {
	if (x >= y) return x;
	else if (x < y) return y;
}
```

A *priori* podríamos pensar: si ```(x >= y)``` no se cumple seguro que ```(x < y)```si que se cumple. No obstante, esta función da error de compilación, pues el compilador no entiende de significados, sino de sintaxis.

#### Llamada de una función

Una vez tenemos la función definida, podemos llamarla (usar) desde cualquier parte del código.

**Ejemplo:** *Llamaremos a la función max2 desde main*

```cpp
int max2(int x, int y) {
	if (x > y) return x;
	return y;
}

int main() {
	int p = 4;
	int q = 10;
	cout << max2(p, q) << endl;
/*
	Durante la ejecución, en el momento que llegue a
	max2(p,q) el programa va a volver a la linea del código
	de max2 y ejecutara el códgio de manera secuencial.
	
	Una vez llegue al return, toda la expresión max2(p,q)
	tomará el valor de lo que retorna la función. En este
	caso, max2(p, q) --> 10;
*/
}
```

## Acción

Es la forma de encapsular cuando no se devuelve ningún valor (como
hacen las funciones). Generalmente, identificamos que la tarea tiene alguno de los puntos de a continuación:
* No tiene parámetros de salida. 
* Tiene 2 o más parámetros de salida y/o 1 o más parámetros de entrada/salida.

¡En una acción no vamos a poner un return!

#### Sintaxis de una acción:
```cpp
void action_name (params_list) {
	I1; // Instrucciones
	...;
	In;
	// NUNCA con un void va a haber un return;
}
```

**Sintaxis de la lista de parametros:**
* Para los parámetros de entrada: ```data_type param1```
* Para los parámetros de salida o entrada/salida: ```data_type& param1```

Como norma general, para ser mas ordenados, primero escribiremos los parámetros de entrada, y, luego, los parámetros de salida o entrada/salida.

Podemos distinguir dos tipos de pasos de variables (dependiendo de si llevan ```&``` o no).

* **Paso de parámetro por valor:** No llevan ```&```
	En este caso, se pasa el valor del parámetro, no su referencia, por lo tanto se trata como en las funciones, no se modifica la variable original.

* **Paso de parámetro por referencia:** **SI** llevan ```&```
	En este caso, se pasa la referencia de la variable, por lo tanto la variable original va a ser modificada, pues modifica la referencia de memoria de esta variable.
	
	Es decir, si a la variable con la que hacemos la llamada es ```a``` y dentro del bloque de la acción es la variable ```x```, a nivel memoria, ```a``` y ```x``` son exactamente la misma variable.
	
**Ejemplo:** *Intercambio de valor de dos variables*

```cpp
// PRE: x (vale A) entera, y (vale B) entera.
// POST: x vale B, e y vale A

void intercambio(int& x, int& y) {
	int aux = x;
	x = y;
	y = aux;
}

int main() {
	int a = 5;
	int b = 10;
	
	intercambio(a, b); // UNA ACCIÓN SIEMPRE SE LLAMA EN UNA
	// LINEA DEDICADA SOLAMENTE A LLAMAR A LA ACCIÓN
	cout << a << ' ' << b << endl;
}
```

**Ejemplo:** *En este ejemplo veremos variables con & y sin él.*

```cpp
void div_entera(int x, int y, int& c, int& r) {
	c = x / y;
	r = x % y;
}

int main() {
	int a = 15;
	int b = 10;
	int cociente, resto; //Aquí no tienen un valor válido
	div_entera(a + 5, b, cociente, resto);
	
	cout << cociente << ' ' << resto << endl;
}
```

En este código podemos observar diversas cosas:
1. ```a``` y ```b``` son parámetros con paso de valor, es decir, solo son de entrada y el valor de ```a``` y ```b``` no van a ser modificados. ```a``` es quien le da valor a ```x``` y ```b```es quien le da valor a ```y```.
2. El valor de ```cociente``` y ```resto``` en el bloque ```main()``` no tienen un valor válido, aún así, ¡no importa! Pues es el bloque ```div_entera()``` quien se encarga de darle un valor, ya que la variable ```cociente``` y ```c``` están "conectadas". Lo mismo pasa para la variable ```resto``` y ```r```.

*IMPORTANTE: el punto 2, solo aplica cuando son parámetros de salida **únicamente**, en caso de ser parámetros de entrada o entrada/salida si es necesario que el valor de las variables con las que llamo a la acción sea valido.*