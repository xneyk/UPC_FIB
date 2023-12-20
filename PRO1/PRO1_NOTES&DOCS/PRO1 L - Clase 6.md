# Maneras de trabajar con funciones

### Definición de la función junto a su cabecera
Una manera de definir y usar funciones es la que sale a continuación, que es del mismo modo al que se vio en [PRO1 T - Clase 6](PRO1%20T%20-%20Clase%206.md)

```cpp
data_type function_name (data_type_x x, data_type_y type y) {
	...
}
```

Definiendo la función justo después de su cabecera, es necesario definir su código asociado en ese mismo momento.

Por como el compilador funciona, definiendo las funciones de este modo para usar una función, lineas antes debes haber definido la función. De este modo, si tienes dos funciones que se llaman una a la otra y la otra a la una, es imposible definirlas de este modo.

### Anunciar la cabecera de la función y posteriormente definirla.

Otro modo muy usado para definir funciones es anunciar primero su cabecera y posteriormente definir el código asociado a esta.

```cpp
data_type function_name (data_type_x x, data_type_y type y);

int main () {
	...
}

data_type function_name (data_type_x x, data_type_y type y) {
	...
}
```

De este modo, estamos anunciando primero la función, de modo que el programa ya se espera esa función, y, posteriormente, la estamos definiendo debajo.