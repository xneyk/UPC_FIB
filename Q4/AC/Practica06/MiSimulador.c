#include "CacheSim.h"

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
   // unsigned char dirty;
   unsigned char valid;
   unsigned int tag;
};

struct cache_line tag_memory[CACHE_SIZE / BLOCK_SIZE];

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache() {
   /* Escriu aqui el teu codi */

   for (int i = 0; i < (CACHE_SIZE / BLOCK_SIZE); ++i) {
      tag_memory[i].valid = false;
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

	byte = address & (BLOCK_SIZE - 1);
	bloque_m = address >> OFFSET_BITS;
	linea_mc = bloque_m & (CACHE_SIZE / BLOCK_SIZE - 1);
	tag = bloque_m >> LINE_BITS;
	
	miss = !(tag_memory[linea_mc].valid && tag_memory[linea_mc].tag == tag);
	replacement = miss && !LE && tag_memory[linea_mc].valid; // write no allocate, nomes hi ha replacement si es lectura

	lec_mp = miss && !LE;
	esc_mp = LE; // es una escriptura

	if (miss && !LE) { // si es miss de lectura portem el bloc a MC
		mida_lec_mp = BLOCK_SIZE;
		tag_out = tag_memory[linea_mc].tag;
		tag_memory[linea_mc].valid = true;
		tag_memory[linea_mc].tag = tag;
	}

	if (LE) mida_esc_mp = 1;

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
}
