#include <errno.h>  /* errno   */
#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <stdio.h>
#include "inc/arbBin.h"

struct arbbin *creaArbbin() {
	struct arbbin *arbol = NULL;
	arbol = malloc(sizeof(struct arbbin));

	if (arbol == NULL) {
		errno = ENOMEM;
		perror("Error al reservar memoria para el árbol (malloc)\n");
		return NULL;
	}
	
	arbol->raiz    = NULL;
	arbol->numelem = 0;

}

struct abNodo *creaAbnodo(uint8_t v) {
	struct abNodo *nodo = NULL;
	
	nodo = malloc(sizeof(struct abNodo));

	if (nodo == NULL) {
		errno = ENOMEM;
		perror("Error al reservar memoria para el nodo (malloc)\n");
		return NULL;
	}

 	nodo->dcha  = NULL;
	nodo->izda  = NULL;
	nodo->valor = v;

	return nodo;
}

void insertaNodo(struct arbbin *arb, struct abNodo *n) {
	struct abNodo *sig  = NULL;
	struct abNodo *nodo = NULL;
	if (arb->raiz == NULL) {
		arb->raiz = n;
		arb->numelem++;
	}
	else {
		if (n->valor < arb->raiz->valor) {

		}
	}

}

void imprimeArbbin(struct arbbin *arb) {
	uint8_t visitados = 0;
	struct abNodo *nodo = NULL;
	nodo = arb->raiz;
	while (visitados != arb->numelem) {
		visitados++;
	}
}


/* 1. libera cada nodo  
   2. libera arbol
*/
void freeArbbin(struct arbbin *arb) {
}
