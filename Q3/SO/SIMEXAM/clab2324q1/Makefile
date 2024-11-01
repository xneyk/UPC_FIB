all: mostrarJP crearJP

mostrarJP: mostrarJP.c
	gcc -o mostrarJP mostrarJP.c

crearJP: crearJP.c
	gcc -o crearJP crearJP.c

tar: 
	tar zcvf clab1.tar.gz Makefile *.c
clean:
	rm mostrarJP crearJP