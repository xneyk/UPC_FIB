Esta clase se ha dedicado a hacer ejercicios, el temario ya se ha acabado y estamos repasando ejercicios de diversos temas.

*¡Cuidado!*
```v.size()``` se interpreta como entero **SIN SIGNO** por lo que si hacemos una comparación entre un negativo y un ```x.size()``` el valor negativo se interpretara como un entero positivo (no en Ca2) por lo que dará el contrario de lo que queremos hacer.
--> Una posible solución seria hacer ```ìnt(x.size())``` para que ```x.size()``` se interprete como un entero con signo, o bien, haberle asignado a una variable tipo ```int```el valor de ```x.size()``` y hacer la comparación con la variable.

