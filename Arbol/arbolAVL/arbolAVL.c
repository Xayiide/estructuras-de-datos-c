#include <errno.h>  /* errno   */
#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <stdio.h>  /* perror  */

#include "inc/arbolAVL.h"

static void    borraNodo  (nodoavl* nodo);
static void    imprimeNodo(nodoavl* nodo);
static uint8_t max        (uint8_t a, uint8_t b);
static uint8_t inserta    (nodoavl **raiz, nodoavl *nodo);


static uint8_t max(uint8_t a, uint8_t b) {
	uint8_t max;

	if (a >= b)
		max = a;
	else
		max = b;

	return max;
}


arbolavl *creaAVL() {
	arbolavl *arbol = NULL;
	arbol = malloc(sizeof(arbolavl));

	if (arbol == NULL) {
		errno = ENOMEM;
		perror("creaAVL.\n");
		return NULL;
	}

	arbol->raiz    = NULL;
	arbol->numelem = 0;

	return arbol;
}

static void borraNodo(nodoavl* nodo) {
	if (nodo->izda != NULL) {
		borraNodo(nodo->izda);
	}

	if (nodo->dcha != NULL) {
		borraNodo(nodo->dcha);
	}

	free(nodo);
}

void borraAVL(arbolavl *arb) {
	struct nodoavl* nodo = NULL;

	if (arb == NULL) {
		printf("Error. Árbol nulo.\n");
		return;
	}

	nodo = arb->raiz;
	if (nodo != NULL) {
		borraNodo(nodo);
		return;
	}
	else {
		printf("El árbol está vacío.\n");
	}

	free(arb);

}

static uint8_t inserta(nodoavl **raiz, nodoavl *nodo) {
	nodoavl *r = *raiz;
	uint8_t res = 0;

	if (r == NULL) {
		*raiz = nodo;
		res   = 1;
	}
	else {
		if (nodo->valor == r->valor) {
			printf("Ese valor ya está en el árbol\n");
			res = 0;
		}
		else if (nodo->valor < r->valor) {
			res = inserta(&(r->izda), nodo);
		}
		else {
			res = inserta(&(r->dcha), nodo);
		}
	}
	return res;
}

uint8_t insertaNodo(arbolavl *arb, uint8_t valor) {
	nodoavl *nodo = malloc(sizeof(nodoavl));
	uint8_t res;

	if (nodo == NULL) {
		errno = ENOMEM;
		perror("Error al reservar memoria para el nodo (malloc).\n");
		return 0;
	}

	nodo->dcha = nodo->izda = NULL;
	nodo->valor = valor;

	res = inserta(&(arb->raiz), nodo);
	if (res == 1)
		arb->numelem++;

	return res;
}




static void imprimeNodo(nodoavl *nodo) {
	if (nodo->izda != NULL) {
		printf("%d -> %d;\n", nodo->valor, nodo->izda->valor);
		imprimeNodo(nodo->izda);
	}

	if (nodo->dcha != NULL) {
		printf("%d -> %d;\n", nodo->valor, nodo->dcha->valor);
		imprimeNodo(nodo->dcha);
	}
}

void imprimeArbolAVL(arbolavl* arb) {
	struct nodoavl *nodo = NULL;

	if (arb == NULL) {
		printf("Error. Árbol nulo.\n");
		return;
	}

	nodo = arb->raiz;
	if (nodo == NULL) {
		printf("El árbol está vacío.\n");
	}
	else {
		printf("digraph {\n");
		imprimeNodo(nodo);
		printf("}\n");
	}
}


tiponodo tipoNodo(nodoavl *nodo) {
	tiponodo tipo;

	if (nodo == NULL) {
		printf("El nodo es nulo.\n");
		return 0;
	}
	else if ((nodo->izda == NULL) && (nodo->dcha == NULL)) {
		tipo = HOJA;
	}
	else if ((nodo->izda != NULL) && (nodo->dcha != NULL)) {
		tipo = COMPLETO;
	}
	else {
		tipo = INCOMPLETO;
	}

	return tipo;
}

uint8_t altura(nodoavl *nodo) {
	uint8_t  altura;
	tiponodo tipo;

	tipo = tipoNodo(nodo);

	if (tipo == HOJA) {
		altura = 0;
	}
	else { /* tipo es COMPLETO porque no puede haber incompletos (?) */
		altura = 1 + max(nodo->izda->altura, nodo->dcha->altura);
	}

	return altura;
}

int8_t factorBalance(nodoavl *nodo) {
	int8_t factor;
	tiponodo tipo;

	if (nodo == NULL) {
		printf("Error. Nodo nulo.\n");
		return 0;
	}

	tipo = tipoNodo(nodo);

	if (tipo == HOJA) {
		printf("Factor de balance: el nodo es una hoja.\n");
		return 0;
	}

	factor = nodo->izda->altura - nodo->dcha->altura;

	printf("factor de balance: %d\n", factor);

	return factor;
}

