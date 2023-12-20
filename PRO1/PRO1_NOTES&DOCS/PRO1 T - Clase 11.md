#Teoría
# Estructuras (Tuplas)
Una estructura o tupla es un tipo de datos complejo que nos permite agrupar bajo el mismo nombre un conjunto **fijo** de valores. Estos valores pueden ser de **diferentes tipos de valores**.
* Numero FIJO de elementos
* Elementos **NO** necesariamente del mismo tipo de dato.

**Ejemplo:** Una estructura "Reloj" que almacena "hora (int)", "minuto (int)", "segundo (int)".

***Cada valor de la tupla se denomina campo y tienen...***
1. Un nombre: siempre en minúscula
2. Un tipo de datos: cualquiera de los que hemos visto.

## Sintaxis
Una tupla o estructura se declara siguiendo el siguiente esquema:
```cpp
struct Name_struct {
	data_type campo1;
	...
	data_type campoN;
}; // <-- importante el punto y coma
```

Como recomendación, siempre haremos las definiciones de las estructuras en lo mas alto del *```scope```*, es decir, debajo de la cabecera, seguido de los ```#include```.

*Observación: ```struct``` no tiene definidos los operadores de comparación ```>, >=, <, <=, !=, ==, ...*```. 

### Acceso a los campos de una estructura
Para acceder a los campos de una tupla, nos referiremos al nombre de la tupla y al nombre del campo separados por un punto.

```cpp
struct Car {
	string brand; // Nombre de la marca del coche.
	int HP, n_doors; // Caballos y numero de puertas.
};

int main() {
	Car my_own_car;
	
	my_own_car.brand = "BMW";
} 
```

### Operador asignación
El operador asignación entre tuplas funciona **siempre y cuando sean del mismo tipo de tupla.** Este funciona campo a campo.

```cpp
struct Car {
	string brand; // Nombre de la marca del coche.
	int HP, n_doors; // Caballos y numero de puertas.
};

struct Van {
	string brand; // Nombre de la marca del coche.
	int HP, n_doors; // Caballos y numero de puertas.
};

int main() {
	Car my_own_car;
	
	my_own_car.brand = "BMW";
	my_own_car.HP = 159;
	my_own_car.n_doors = 3;
	...
	
	Car my_second_car = my_own_car; ✅
	Van my_van = my_own_car; ❌ // Aunque tengan los mismos campos.
}
```

### Paso de parámetros.
* **Paso por valor:** Si la estructura tiene pocos campos y son de datos simples nos lo podemos permitir, pues la copia no es costosa.
* **Paso por referencia constante:** De igual modo, si la estructura tiene muchos campos o son de tipos de datos complejos usaremos la misma técnica que con los vectores, el paso por referencia (```&```)  **constante**.

## Tuplas Anidadas
Como era de esperar, una tupla puede tener otras tuplas como campo. Veamos un ejemplo.

```cpp
struct Nif {
	int dni;
	char letra;
};

struct Persona {
	string nombre;
	Nif nif;
	int edad;
};

int main() {
	Persona p;
	p.nombre = "Edgar"
	p.edad = 18;
	p.nif.dni = 45454367; // Acceso al campo nif y luego a su campo dni
	p.nif.letra = 'A';
}
```
