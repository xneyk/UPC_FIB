#Laboratorio
# Primers pasos

* Qualsevol programa de C++ comença de la seguent manera...
```cpp
#include <iostream>
using namespace std;
```

* La funció principal del programa serà la funció ```main()```.
```cpp
#include <iostream>
using namespace std;

int main(){
	//Code Here!
}
```

## cout, Misstages per consola.

La manera amb la que podem imprimir text per la consola a C++ es utilitzant la paraula clau ```cout```
```cpp
#include <iostream>
using namespace std;

int main(){
	cout << "Hello World" << endl
}
```

## Compilar un programa (LAB)

```p1++ -o nomDelArxiu.x nomDelArxiu.cc```

Aquest serveix per al compilador del laboratori, p1++ es un compilador que ha creat la FIB per poder utilitzar al LAB.

*p1++ es el compilador creat per la FIB per a PRO1, la instrucció per a compliar amb qualsevol compilador segueix la següent expresió*

```compilador -o nomDelArxiu nomDelArxiu.cc```

## cin, Inputs per consola.

Si volem que el valor d'una variable sigui entrada per l'usuari, ho podem fer usant la paraula clau ```cin``` de la següent manera.

```cpp
#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	cout << "El numero entrat ha estat: " << a << endl;
}
```

Si ens fixem, veiem que per sortides utilitzem **<<** i per a les entrades **>>**.
