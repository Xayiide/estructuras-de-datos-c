#include <errno.h>  /* errno   */
#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <stdio.h>
#include "inc/arbBin.h"



/* Funciones internas */
static uint8_t insertaNodo(struct abNodo** raiz, struct abNodo* n);
static void    imprimeNodo(struct abNodo* n);

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

	return arbol;
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

/* puntero doble porque si no, no puedo modificarlo */
static uint8_t insertaNodo(struct abNodo **raiz, struct abNodo *n) {
	struct abNodo *r = *raiz;
	uint8_t res = 0;
	if (r == NULL) {
		*raiz = n;
		res   = 1;
	}
	else {
		/* Intentamos insertar el mismo valor */
		if (n->valor == r->valor) {
			printf("No se puede insertar dos veces el mismo valor\n");
			res = 0;
		}
		else if (n->valor < r->valor) {
			res = insertaNodo(&(r->izda), n);
		}
		else { /* n->valor > raiz->valor */
			res = insertaNodo(&(r->dcha), n);
		}
	}
	return res;
}

uint8_t inserta(struct arbbin* arb, uint8_t v) {
	struct abNodo *nodo = malloc(sizeof(struct abNodo));
	uint8_t res;
	if (nodo == NULL) {
		errno = ENOMEM;
		perror("Error al reservar memoria para el nodo (malloc)\n");
		return 1;
	}

	nodo->dcha = nodo->izda = NULL;
	nodo->valor = v;

	res = insertaNodo(&(arb->raiz), nodo);
	if (res == 1)
		arb->numelem++;

	return res;
}


static void imprimeNodo(struct abNodo* nodo) {
	if (nodo->izda != NULL) {
		printf("%d -> %d;\n", nodo->valor, nodo->izda->valor);
		imprimeNodo(nodo->izda);
	}
	if (nodo->dcha != NULL) {
		printf("%d -> %d;\n", nodo->valor, nodo->dcha->valor);
		imprimeNodo(nodo->dcha);
	}
}

void imprimeArbbin(struct arbbin *arb) {
	struct abNodo *nodo = NULL;
	nodo = arb->raiz;

	if (nodo != NULL) {
		printf("digraph {\n");
		imprimeNodo(nodo);
		printf("}\n");
	}
	else {
		printf("El arbol está vacío\n");
	}
}


/* 1. libera cada nodo  
   2. libera arbol
*/
