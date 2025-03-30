all: sim sim2

sim: MiSimulador.c CacheSimWT.o CacheSim.h
	gcc -m32 CacheSimWT.o MiSimulador.c tiempo.c -o sim

sim2: MiSimulador2.c CacheSimCB.o CacheSim.h
	gcc -m32 CacheSimCB.o MiSimulador2.c tiempo.c -o sim2

clean:
	rm -f sim sim2