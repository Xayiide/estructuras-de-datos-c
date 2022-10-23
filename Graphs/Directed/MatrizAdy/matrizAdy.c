#include <stdlib.h> /* malloc  */
#include <stdint.h> /* uint8_t */
#include <errno.h>  /* errno   */
#include <assert.h> /* assert  */
#include <stdio.h>
#include "inc/matrizAdy.h"

struct grafo *creaGrafo(uint8_t numnodos) {
	uint8_t i;
	struct grafo *g = malloc(sizeof(struct grafo));

	if (g == NULL) {
		errno = ENOMEM;
		printf("Error reservando memoria para crear el grafo (malloc)\n");
		return NULL;
	}

	g->numnodos = numnodos;
	
	g->adys = calloc(sizeof(uint8_t *), g->numnodos);
	if (g->adys == NULL) {
		errno = ENOMEM;
		printf("Error reservando memoria para las adys. (calloc)\n");
		free(g);
		return NULL;
	}

	for (i = 0; i < g->numnodos; i++) {
		g->adys[i] = calloc(sizeof(uint8_t *), g->numnodos);
		if (g->adys[i] == NULL) {
			errno = ENOMEM;
			printf("Error reservando memoria para lista adys. (calloc)\n");
			freeGrafo(g);
			return NULL;
		}
	}

	return g;
}

void freeGrafo(struct grafo *g) {
	uint8_t i;

	if (g->adys == NULL) {
		printf("Algo ha ido muy mal liberando el grafo\n");
		return;
	}

	for (i = 0; i < g->numnodos; i++) {
		if (g->adys[i] != NULL) {
			free(g->adys[i]);
		}
	}

	free(g->adys);
	/* free(g) */
}

/* formato .dot para graphviz */
void imprimeGrafo(struct grafo *g) {
	uint8_t desde, hasta;
	
	printf("digraph {\n");

	for (desde = 0; desde < g->numnodos; desde++) {
		for (hasta = 0; hasta < g->numnodos; hasta++) {
			if (g->adys[desde][hasta]) {
				printf("%d -> %d;\n", desde, hasta);
			}
		}
	}

	printf("}\n");

}

uint8_t creaArista(struct grafo *g, uint8_t desde, uint8_t hasta) {
	assert(g != NULL);
	assert(desde < g->numnodos);
	assert(hasta < g->numnodos);

	if (tieneArista(g, desde, hasta)) {
		fprintf(stderr, "El grafo ya tiene esa arista\n");
		return 1;
	}

	g->adys[desde][hasta] = 1;
	return 0;
}

uint8_t tieneArista(struct grafo *g, uint8_t desde, uint8_t hasta) {
	assert(g != NULL);
	assert(desde < g->numnodos);
	assert(hasta < g->numnodos);

	uint8_t res = 0;

	res = g->adys[desde][hasta] == 1 ? 1 : 0;

	return res;
}

