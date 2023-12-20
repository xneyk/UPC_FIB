En esta clase continuaremos viendo los algoritmos de ordenación más fundamentales.

# Algoritmo de Burbuja
En este algoritmo podemos hacer un símil, en el cual los elementos son burbujas. Si un elemento ```a``` es mejor que un elemento ```b``` significará que la burbuja es "más grande" y por lo tanto subirá más alto.

Los pasos del algoritmo son los siguientes:
1. Empezamos por el indice ```0``` y recorremos todo el vector desde la ultima posición hacia el indice ```0```, es decir, de derecha a izquierda.
2. Vamos comparando por parejas (si ```[n-2]``` es mejor que ```[n-1]```, los intercambiamos. Luego si ```[n-3]``` es mejor que ```[n-2]``` los intercambiamos...
3.  Si seguimos con este patrón, llegamos a un punto en el que comparamos ```[0]``` y ```[1]```. En este punto habremos traído el elemento correcto a ```v[0]```.
4. Repetimos el proceso pero desde ```v[1]```
5. Si en algún momento hacemos una iteración entera sin hacer ningún cambio significará que la parte por tratar ya esta correctamente ordenada, por lo que podemos considerarla como tratada y dejar de hacer iteraciones.
6. En caso contrario en el peor de los casos pararemos cuando lleguemos a partir desde ```v[n-1]```, pues en ese punto podemos estar 100% seguros de que todo esta correctamente ordenado.

## Código Algoritmo de Burbuja
```cpp
void swap(int& a, int&b) {
	int aux = a;
	a = b;
	b = aux;
}

// ... SEGUIR LUEGO CODIGO FOTO
```
![](Pasted%20image%2020231212143853.png)

# Ordenación por fusión
*BUSCAR MERGE SORT PARA ENTENDER MEJOR*

![Esquema de llamadas recursivas del algoritmo *Merge Sort*](MergeSort_Llamadas_Recursivas.png)

