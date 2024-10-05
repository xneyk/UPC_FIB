#include <stdio.h>	// include per sprintf
#include <stdlib.h>	// include de la libreria standard
#include <unistd.h>	// include per write
#include <string.h>	// include per strlen

/**
 * Muestra un mensaje descriptivo sobre el uso del programa y aborta la ejecucion.
*/
void usage(char *str) {
	char buffer[512];
	sprintf(buffer, "Usage: %s arg1 [arg2..argn]\nEste programa escribe por su salida la lista de argumentos que recibe.\n(Debe recibir al menos un argumento)\n", str);
	write(1, buffer, strlen(buffer));

	exit(0); // abort without error.
}

int main(int argc,char *argv[]) {
	// Comprovacion del numero de parametros.
	if (argc <= 1) usage(argv[0]); // si no recibe al menos un parametro (el nombre del programa esta siempre) 

	char buf[80];
	for (int i = 0; i < argc; i++) {
		if (i == 0) {
			sprintf(buf, "El argumento %d es %s (es el nombre del ejecutable)\n", i, argv[i]);
		} else {
			sprintf(buf, "El argumento %d es %s\n", i, argv[i]);
		}
		write(1, buf, strlen(buf));
	}
	return 0;
}
