# Correctesa de programes recursius iteratius

[*Documentació de la pàgina de la assignatura*](https://www.cs.upc.edu/pro2/data/uploads/it_rec_corr.pdf)

---

# 1. Demostració de programes iteratius.

Per a poder demostrar formalment que un algoritme iteratiu funciona, necesitem allò al que anomenem ***Invariant*** i ***Funció de Fita***.

- **Invariant (I):** Condició que s’ha de complir abans d’entrar, durant i després del bucle.
- **Funció de Fita:** Expresió que ha d’anar decreixent per poder demostrar que el bucle acaba.

### Estructura de la justificació

La justificació es pot dividir en cinc pasos, alhora aquests 5 es poder agrupar en dos blocs més grans.

1. L’invariant es cumpleix el primer cop que arribem al bucle
2. Suposant l’Invariant i que la condició del bucle s’avalua a cert, llavors, després d’executar el cos del bucle l’Invariant es torna a cumplir.
3. Suposant l’Invariant i que la condició del bucle s’evalua a fals, llavors, la postcondició es cumpleix.

---

1. Suposant l’Invariant i que la condició del bucle s’avalua cert, llavors, després d’executar el cos del bucle, la funció fita s’avalua a quelcom menor.
2. L’Invariant implica que la funció fita no és negativa.

---

**Exemple:**

```cpp
// Pre: v és de la forma 0^n1^m per n,m>=0.
// Post: retorna l'índex de l'últim 0.
int find(const vector<int> v) {
	int left = -1;
	int right = v.size();
	// Invariant (I): v[left]=0 i v[right]=1
	// Funció de fita: sup - inf.
	while (left+1 < right) {
		int mid = (left+right)/2;
		if (v[mid] == 0) left = mid;
		else rigth = mid;
	}
	
	return left;
}
```

# 2. Demostració d'algoritmes recursius

A la classe anterior varem veure com demostrar la correcció d'un algoritme iteratiu. En aquesta sessió veurem com demostrar-ho en el cas d'un algoritme recursiu.

En primer lloc veurem una manera iterativa de solucionar el problema de saber si una determinada cadena `s` és cap i cua o no.

```cpp
bool capicua(const string& s) {
	for (int i = 0, j = n-1 ; i < n; ++i, --j){
		if (s[i] != s[j]) return false;
	}

	return true;
}

```

---

***Per saber quan triga l'execució d'un programa podem fer servir a la linea de comandes la comanda `time` de la seguent manera:*** `time ./file.x`

Al fer l'execució amb la comanda time veurem una cosa similar a el seguent:

```
real   XX.xxx s --> Temps que ha estat el programa "obert"
usr    XX.xxx s
sys    XX.xxx s --> Temps d'execució

```

---

*Implementació recursiva:*

```cpp
bool capicua (const string& s) {
	int n = s.size();
	if (n < 2) return true;
	if (s[0] != s[n-1]) return false;
	else return capicua(s.substr(1, n-2));
}

```

> El métode  .substr() aplica sobre el mateix string s, retorna el substring de s el cual comença a l'index i (primer argument del metode i té mida m (segon argument del métode).
Cuidado, té un cost O(n) causant que la anterior funció capicua() tingui cost O(n*n).
>