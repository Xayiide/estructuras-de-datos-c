#ifndef _MATRIZADY_H_
#define _MATRIZADY_H_

#include <stdint.h> /* uint8_t */

struct grafo {
	int       numnodos;
	uint8_t **adys;
};

struct grafo *creaGrafo(uint8_t numnodos);
void    freeGrafo      (struct grafo *g);
void    imprimeGrafo   (struct grafo *g);
uint8_t creaArista     (struct grafo *g, uint8_t desde, uint8_t hasta);
uint8_t tieneArista    (struct grafo *g, uint8_t desde, uint8_t hasta);

#endif

