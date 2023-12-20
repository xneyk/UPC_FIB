#Laboratorio
# Operadores Lógicos

C++ acepta expresar los operadores lógicos como se expresaban en C, no obstante, es preferible expresarlos tal y como se debe hacer en C++.

| C++ | C | Equivalencia a la realidad |
|------|------|------|
|```and```|```&&```|i|
|```or```|```//```|o|
|```not```|```!```|negació|
|```==```|```==```|comparación|
|```!=```|```!=```|desigualdad|
|```>```|```>```|mayor que|
|```<```|```<```|menor que|
|```>=```|```>=```|mayor o igual que|
|```<=```|```<=```|menor que|

*Se ha escrito ```//``` en lugar de ```||``` ya que sino este símbolo se interpreta como otro apartado más de la columna, el símbolo correcto para el operador OR es --> ```||```*

## Conversiones de tipo
### Integer a Double

```cpp
int a = 5;
cout << double(a); // double(a) --> 5.0
```

### Double a Integer

```cpp
double a = 5.8;
cout << int(a); // int(a) --> 5
```

Al pasar de decimal a entero, devuelve la parte decimal, se "carga" la parte decimal indistintamente de que sea >= a .5.