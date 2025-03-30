#include "CacheSim.h"
#include <stdio.h>

/**
 * Las direcciones son de 32 bits (para simpliﬁcar asumiremos que todos los accesos son a bytes)
 * La cache será de mapeo directo
 * Tamaño de la cache: 4 Kbytes
 * Tamaño de la línea de cache: 32 bytes
 * Política de escritura: Write Through
 * Política de emplazamiento: Write NO Allocate
 */

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

#define CACHE_SIZE	4096
#define BLOCK_SIZE	32
#define OFFSET_BITS	5 // 32 = 2^5
#define LINE_BITS		7 // 4096 / 32 = 128 = 2^7


struct cache_line {
   unsigned char dirty;
   unsigned char valid;
   unsigned int tag;
};

struct cache_line tag_memory[CACHE_SIZE / BLOCK_SIZE];

/**
 * Performance Couters
 */

unsigned int n_access;
unsigned int n_miss;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache() {
   /* Escriu aqui el teu codi */

   for (int i = 0; i < (CACHE_SIZE / BLOCK_SIZE); ++i) {
      tag_memory[i].valid = false;
      tag_memory[i].dirty = false;
   }
}

/* LE = 1 iff es escriptura */
/* La rutina reference es cridada per cada referencia a simular */
void reference(unsigned int address, unsigned int LE) {
   unsigned int byte;
   unsigned int bloque_m;
   unsigned int linea_mc;
   unsigned int tag;
   unsigned int miss;
   unsigned int lec_mp;
   unsigned int mida_lec_mp;
   unsigned int esc_mp;
   unsigned int mida_esc_mp;
   unsigned int replacement;
   unsigned int tag_out;

   /* Escriu aqui el teu codi */
   ++n_access;

	byte = address & (BLOCK_SIZE - 1);
	bloque_m = address >> OFFSET_BITS;
	linea_mc = bloque_m & (CACHE_SIZE / BLOCK_SIZE - 1);
	tag = bloque_m >> LINE_BITS;
	
	miss = !(tag_memory[linea_mc].valid && tag_memory[linea_mc].tag == tag);
	replacement = miss && tag_memory[linea_mc].valid;

   esc_mp = replacement && tag_memory[linea_mc].dirty; // S'escriu en replace d'un block modificat
   lec_mp = miss;
   
   if (miss) {
      ++n_miss;
      mida_lec_mp = BLOCK_SIZE;
      if (tag_memory[linea_mc].dirty) mida_esc_mp = BLOCK_SIZE;

      tag_out = tag_memory[linea_mc].tag;
      tag_memory[linea_mc].tag = tag;
      tag_memory[linea_mc].dirty = false;
      tag_memory[linea_mc].valid = true;
   }

   if (LE) tag_memory[linea_mc].dirty = true; // si es una escriptura modifica el block sigui hit o miss

   /* La funcio test_and_print escriu el resultat de la teva simulacio
    * per pantalla (si s'escau) i comproba si hi ha algun error
    * per la referencia actual
    * */
   test_and_print(address, LE, byte, bloque_m, linea_mc, tag,
                  miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
                  replacement, tag_out);
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
