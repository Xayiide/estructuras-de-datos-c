#include <errno.h>  /* errno   */
#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <stdio.h>
#include "inc/arbBin.h"


/* Funciones internas */
static struct abNodo *buscaNodo(struct abNodo* nodo, uint8_t v);

static uint8_t insertaNodo   (struct abNodo** raiz, struct abNodo* n);
static void    imprimeNodo   (struct abNodo* nodo);
static void    recorrePre    (struct abNodo* nodo);
static void    recorreCentral(struct abNodo* nodo);
static void    recorrePost   (struct abNodo* nodo);
static void    borraNodo     (struct abNodo* nodo);
static uint8_t compruebaRDcha(struct abNodo* nodo);
static uint8_t compruebaRIzda(struct abNodo* nodo);



struct arbbin *creaArbbin() {
	struct arbbin *arbol = NULL;
	arbol = malloc(sizeof(struct arbbin));

	if (arbol == NULL) {
		errno = ENOMEM;
		perror("Error al reservar memoria para el árbol (malloc).\n");
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
		perror("Error al reservar memoria para el nodo (malloc).\n");
		return NULL;
	}

 	nodo->dcha  = NULL;
	nodo->izda  = NULL;
	nodo->valor = v;

	return nodo;
}

static struct abNodo *buscaNodo(struct abNodo* nodo, uint8_t v) {
	struct abNodo *n = NULL;

	if (v == nodo->valor) {
		n = nodo;
	}
	else if (v < nodo->valor) {
		if (nodo->izda == NULL) {
			printf("El valor buscado no existe.\n");
			n = NULL;
		}
		else {
			n = buscaNodo(nodo->izda, v);
		}
	}
	else if (v > nodo->valor) {
		if (nodo->dcha == NULL) {
			printf("El valor buscado no existe.\n");
			n = NULL;
		}
		else {
			n = buscaNodo(nodo->dcha, v);
		}
	}

	return n;
}

struct abNodo *buscaValor(struct arbbin* arb, uint8_t v) {
	struct abNodo *nodo = NULL;
	if (arb == NULL) {
		printf("El árbol es nulo.\n");
		return NULL;
	}

	nodo = arb->raiz;
	if (nodo == NULL) {
		printf("El árbol está vacío.\n");
		return NULL;
	}

	nodo = buscaNodo(nodo, v);

	return nodo;
}

/* puntero doble porque si no no puedo modificarlo */
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
			printf("No se puede insertar dos veces el mismo valor.\n");
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
		perror("Error al reservar memoria para el nodo (malloc).\n");
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
		printf("El árbol está vacío.\n");
	}
}



static void recorrePre(struct abNodo* nodo) {
	printf("%d ", nodo->valor);

	if (nodo->izda != NULL) {
		recorrePre(nodo->izda);
	}

	if (nodo->dcha != NULL) {
		recorrePre(nodo->dcha);
	}
}

static void recorreCentral(struct abNodo* nodo) {
	if (nodo->izda != NULL) {
		recorreCentral(nodo->izda);
	}

	printf("%d ", nodo->valor);

	if (nodo->dcha != NULL) {
		recorreCentral(nodo->dcha);
	}
}

static void recorrePost(struct abNodo* nodo) {
	if (nodo->izda != NULL) {
		recorrePost(nodo->izda);
	}

	if (nodo->dcha != NULL) {
		recorrePost(nodo->dcha);
	}

	printf("%d ", nodo->valor);
}

static void recorreNodo(struct abNodo* nodo, enum ordenRec orden) {
	switch (orden) {
	case PREORDEN:
		recorrePre(nodo);
		break;
	case ORDENCENTRAL:
		recorreCentral(nodo);
		break;
	case POSTORDEN:
		recorrePost(nodo);
		break;
	}

}

void recorreArbbin(struct arbbin* arb, enum ordenRec orden) {
	struct abNodo* nodo = NULL;
	nodo = arb->raiz;

	if (nodo != NULL) {
		recorreNodo(nodo, orden);
		printf("\n");
	}
	else {
		printf("El árbol está vacío.\n");
	}
}


enum tipoNodo tipoNodo(struct abNodo *nodo) {
	enum tipoNodo tipo;

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


static uint8_t compruebaRIzda(struct abNodo* nodo) {
	uint8_t res = 1;
	if (nodo == NULL || nodo->izda == NULL || nodo->dcha == NULL) {
		res = 0;
	}

	if (tipoNodo(nodo) != COMPLETO || tipoNodo(nodo->dcha) != COMPLETO) {
		res = 0;
	}

	if ((tipoNodo(nodo->izda)       != HOJA ||
		 tipoNodo(nodo->dcha->izda) != HOJA ||
		 tipoNodo(nodo->dcha->dcha) != HOJA)) {
		res = 0;
	}

	return res;
}

/* Comprueba todas las condiciones para que un nodo se pueda
 * rotar a la derecha.
 */
static uint8_t compruebaRDcha(struct abNodo* nodo) {
	uint8_t res = 1;

	if (nodo == NULL || nodo->izda == NULL || nodo->dcha == NULL) {
		res = 0;
	}

	if (tipoNodo(nodo) != COMPLETO || tipoNodo(nodo->izda) != COMPLETO) {
		res = 0;
	}

	if ((tipoNodo(nodo->dcha)       != HOJA ||
		 tipoNodo(nodo->izda->izda) != HOJA ||
		 tipoNodo(nodo->izda->dcha) != HOJA)) {
		res = 0;
	}

	return res;
}

void rotaDcha(struct abNodo *nodo) {
	struct abNodo *aux = NULL;
	uint8_t       vaux;

	if (compruebaRDcha(nodo) != 1) {
		printf("El nodo no reúne las condiciones para ser rotado.\n");
		return;
	}

	aux  = nodo->dcha;
	vaux = nodo->valor;

	nodo->dcha        = nodo->izda;
	nodo->valor       = nodo->izda->valor;
	nodo->izda        = nodo->dcha->izda;
	nodo->dcha->izda  = nodo->dcha->dcha;
	nodo->dcha->dcha  = aux;
	nodo->dcha->valor = vaux;

}

void rotaIzda(struct abNodo *nodo) {
	struct abNodo *aux = NULL;
	uint8_t       vaux;

	if (compruebaRIzda(nodo) != 1) {
		printf("El nodo no reúne las condiciones para ser rotado.\n");
		return;
	}

	aux  = nodo->izda;
	vaux = nodo->valor;

	nodo->izda        = nodo->dcha;
	nodo->valor       = nodo->dcha->valor;
	nodo->dcha        = nodo->izda->dcha;
	nodo->izda->dcha  = nodo->izda->izda;
	nodo->izda->izda  = aux;
	nodo->izda->valor = vaux;

}

static void borraNodo(struct abNodo* nodo) {
	if (nodo->izda != NULL) {
		borraNodo(nodo->izda);
	}

	if (nodo->dcha != NULL) {
		borraNodo(nodo->dcha);
	}

	free(nodo);
}

/* Borra nodos en post orden
 * 1. libera cada nodo
 * 2. libera arbol
*/
void borraArbbin(struct arbbin* arb) {
	struct abNodo* nodo = NULL;

	if (arb == NULL) {
		printf("Error. Árbol nulo.\n");
		return;
	}

	nodo = arb->raiz;
	if (nodo != NULL) {
		borraNodo(nodo);
	}
	else {
		printf("El árbol está vacío.\n");
	}

	free(arb);
}
