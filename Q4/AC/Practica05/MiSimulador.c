#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

// gcc -m32 CacheSim.o MiSimulador.c tiempo.c -o sim

#define CACHE_LINES 128    // 2^12 Bytes Cache & 2^5 Bytes per block ==> 2^7 lines = 128 lines
#define FREE_TAG 0x100000  // A TAG has 20 bits (5 hexadecimal digits) ==> 0x100000 is the first non possible TAG.

unsigned int tag_memory[CACHE_LINES];

/**
 * Performance Couters
 */

unsigned int n_access;
unsigned int n_miss;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comencar cada un dels tests.
 * */
void init_cache() {
   totaltime = 0.0;
   /* Escriu aqui el teu codi */
   for (int i = 0; i < CACHE_LINES ; ++i) {
      tag_memory[i] = FREE_TAG;
   }

   n_access = 0;
   n_miss = 0;
}

/* La rutina reference es cridada per cada referencia a simular */
void reference(unsigned int address) {
   unsigned int byte;
   unsigned int bloque_m;
   unsigned int linea_mc;
   unsigned int tag;
   unsigned int miss;         // boolea que ens indica si es miss
   unsigned int replacement;  // boolea que indica si es reemplaca una linia valida
   unsigned int tag_out;      // TAG de la linia reemplacada
   float t1, t2;              // Variables per mesurar el temps (NO modificar)

   t1 = GetTime();
   /* Escriu aqui el teu codi */

   ++n_access; // cache access counter

   byte = address & 0x000000000000001f;      // byte number are 5 less significant bits
   bloque_m = address >> 5;                  // memory_block = address / BLOCK_SIZE
   linea_mc = bloque_m & 0x000000000000007f; // 2^7 = cache size ==> n_block mod 2^7 are 7 less significant bits of n_block.
   tag = bloque_m >> 7;                      // tag = n_block / n_lines

   miss = tag_memory[linea_mc] != tag;       // tag we're looking for is not at it's place.
   replacement = miss && tag_memory[linea_mc] != FREE_TAG;
   
   if (replacement) tag_out = tag_memory[linea_mc];

   if (miss) {
      tag_memory[linea_mc] = tag;
      ++n_miss;
   }
   /* La funcio test_and_print escriu el resultat de la teva simulacio
    * per pantalla (si s'escau) i comproba si hi ha algun error
    * per la referencia actual. Tambe mesurem el temps d'execucio
    * */
   t2 = GetTime();
   totaltime += t2 - t1;
   test_and_print(address, byte, bloque_m, linea_mc, tag, miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */
void final() {
   /* Escriu aqui el teu codi */
   printf("-\n--- Cache Performance Data ---\n");
   printf("- Cache accesses: %*u\n", 35-23, n_access);
   printf("- Miss: %*u\n", 35-13, n_miss);
   printf("- Hit: %*u\n", 35-12, n_access - n_miss);
   double miss_rate = ((double) n_miss)/((double) n_access);
   printf("- Miss Rate: %*f\n", 35-18, miss_rate);
   printf("- Hit Rate: %*f\n", 35-17, 1 - miss_rate);
   printf("\n");
}
