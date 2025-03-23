#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

// gcc -m32 CacheSim2.o MiSimulador2.c tiempo.c -o sim2
#define CACHE_SETS 64            // CACHE TOTAL SIZE = 128 linies ==> 64 linies a cada via.
#define FREE_TAG 0x200000        // last valid tag is 0001 1111 1111 1111 1111 1111 ==> 0x200000 is first invalid tag

unsigned int tag_memory[2][64];  // each tag has 21 bit large
unsigned char last_way_accessed[64];    // stores which way has been accessed more recently

unsigned n_access;
unsigned n_miss;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comencar cada un dels tests.
 * */
void init_cache() {
   totaltime = 0.0;
   /* Escriu aqui el teu codi */
   for (int i = 0; i < CACHE_SETS; ++i) {
      tag_memory[0][i] = FREE_TAG;
      tag_memory[1][i] = FREE_TAG;
      last_way_accessed[i] = 1;
   }

   n_access = 0;
   n_miss = 0;
}

/* La rutina reference es cridada per cada referencia a simular */
void reference(unsigned int address) {
   unsigned int byte;
   unsigned int bloque_m;
   unsigned int conj_mc;
   unsigned int via_mc;
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
   conj_mc = bloque_m & 0x000000000000003f;  // 2^6 = way size ==> n_block mod 2^6 are 6 less significant bits of n_block.
   tag = bloque_m >> 6;                      // tag = n_block / n_sets

   via_mc = 0, miss = false, replacement = false;        // assume hit on way_0
   if (tag != tag_memory[via_mc][conj_mc]) via_mc = 1;   // assume hit on way_1
   if (tag != tag_memory[via_mc][conj_mc]) {
      miss = true;
      ++n_miss;
      via_mc = !last_way_accessed[conj_mc];  // if last_way == 0 --> 1 ; else 0
      replacement = miss && tag_memory[via_mc][conj_mc] != FREE_TAG;
      if (replacement) tag_out = tag_memory[via_mc][conj_mc];

      tag_memory[via_mc][conj_mc] = tag;
   }

   last_way_accessed[conj_mc] = via_mc;   // update last way accessed in order to make LRU work fine.

   /* La funcio test_and_print escriu el resultat de la teva simulacio
    * per pantalla (si s'escau) i comproba si hi ha algun error
    * per la referencia actual. Tambe mesurem el temps d'execucio
    * */
   t2 = GetTime();
   totaltime += t2 - t1;
   test_and_print2(address, byte, bloque_m, conj_mc, via_mc, tag, miss, replacement, tag_out);
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
