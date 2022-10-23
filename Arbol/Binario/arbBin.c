#include <errno.h>
#include <stdint.h>
#include "inc/arbBin.h"

typedef struct arbbn {
	abNodo *izda;
	abNodo *dcha;
	void   *valor;
} abNodo;

typedef struct arbb {
	abNodo *raiz;
	uint8_t numelem;
} arbbin;

arbbin *creaArbbin() {
	arbbin *arbol = NULL;
	arbol = malloc(sizeof(arbbin));

	if (arbol == NULL) {
		errno = ENOMEM;
		perror("Error al reservar memoria para el árbol (malloc)\n");
		return NULL;
	}
	
	arbol->raiz    = NULL;
	arbol->numelem = 0;

}
