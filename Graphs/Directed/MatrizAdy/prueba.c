#include <stdio.h>
#include "inc/matrizAdy.h"


int main(void) {
	struct grafo *g = creaGrafo(5);

	creaArista(g, 0, 1);
	creaArista(g, 1, 2);
	creaArista(g, 2, 4);
	creaArista(g, 1, 4);
	creaArista(g, 0, 2);
	creaArista(g, 2, 2);
	creaArista(g, 2, 3);
	creaArista(g, 2, 3);
	creaArista(g, 3, 1);

	imprimeGrafo(g);

	freeGrafo(g);




	return 0;
}

