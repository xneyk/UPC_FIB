#Laboratorio
# Bucles con centinela

Se le llama centinela a esa condición que hace que el bucle se detenga.

Cuando queramos tratar datos de una manera secuencial, es decir, los datos se procesan a medida que el usuario los introduce, usaremos una condición centinela.

> **Ejemplo:**
> Imaginemos que queremos hacer un programa que acumule (sume) un dato el cual solo admite entradas positivas. En este caso nuestro centinela podría ser -1, pues este no es un numero positivo.

```cpp
int n;
int r;

cin >> n;
while (n != -1) {
	// Tratamiento del dato
	r += n;
	cin >> n; // Pedimos el siguiente dato.
}
```

Ahora imaginemos que no tenemos un centinela. Que la ejecución del bucle se detiene usando el comando ```CTRL + D``` *(En Linux sirve para detener la ejecución de un programa)*.

En este caso, procederemos del mismo modo en el que se explico en la [*Clase 3 de Laboratorio*](Q1/PRO1%20-%20Programació%201/PRO1%20L%20-%20Clase%203).