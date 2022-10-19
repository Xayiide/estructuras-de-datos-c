#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <stdio.h>  /* perror  */
#include <errno.h>  /* errno   */
#include "inc/dobleenlaz.h"


struct dlList* dlLinit() {
	struct dlList* list = NULL;
	list = (struct dlList*) malloc(sizeof(struct dlList*));

	if (list == 0) {
		errno = ENOMEM;
		perror("Error al obtener espacio en memoria (malloc)\n");
		return NULL;
	}
	else {
		list->ppo      = NULL;
		list->numitems = 0;
	}
	return list;
}



/* insert an element v at the beginning of the list */
void dlLinsert(struct dlList* list, void *v) {
	struct dlNode* nodo = NULL;
	nodo = (struct dlNode*) malloc(sizeof(struct dlNode*));

	if (nodo == 0) {
		errno = ENOMEM;
		perror("Error al obtener espacio en memoria (malloc)\n");
		return;
	}

	if (list->numitems == 0) {
		nodo->next = NULL;
	}
	else {
		nodo->next = list->ppo;
		list->ppo->prev = nodo;
	}

	list->ppo   = nodo;
	nodo->prev  = NULL;
	nodo->value = v;
	list->numitems++;
}

int8_t dlLisempty(struct dlList* list) {
	return (list->numitems == 0 ? 1 : 0);
}


uint8_t dlLnumelem(struct dlList* list) {
	return list->numitems;
}

void dlLimprime(struct dlList* list) {
	printf("Se imprime la lista:\n");
	uint8_t i;
	struct dlNode* nodo = NULL;

	if (dlLisempty(list) == 1) {
		return;
	}

	nodo = list->ppo;
	/* No puedo asignar nodo a nodo->next porque en el último elemento
	 * dereferencio a NULL e intento acceder a su next, y eso segfaultea */
	// do {
	// 	printf("[0x%p <- 0x%p -> 0x%p]\n", nodo->prev, nodo, nodo->next);
	// 	nodo = nodo->next;
	// } while (nodo->next != NULL);
	for (i = 0; i < list->numitems; i++) {
	 	printf("[0x%p <- 0x%p -> 0x%p]\n", nodo->prev, nodo, nodo->next);
	 	nodo = nodo->next;
	}
}

/* pos = 0: lee el primer nodo
 * pos = 1: lee el segundo nodo
 * pos = n: lee el nodo enésimo - 1
 * rango válido de pos = [0, numitems -1]
*/
struct dlNode* dlLgetpos(struct dlList* list, int8_t pos) {
	struct dlNode* nodo = NULL;
	int8_t i;
	
	/* Comprueba que la lista tenga elementos */
	if (list->numitems == 0) {
		printf("La lista está vacía\n");
		return NULL;
	}

	/* Comprueba que la posición pertenece al rango correcto */
	if (pos < 0 || pos >= list->numitems) {
		printf("%d está fuera de rango ([0, %hhu])\n",
				pos,
				list->numitems - 1);
		return NULL;
	}

	nodo = list->ppo;

	/* Recorre la lista */
	for (i = 0; i < pos; i++) { /* avanzamos nodo pos veces */
		nodo = nodo->next;
	}

	/* Estamos en el elemento buscado, lo retornamos */
	return nodo;
}



void *dlLpeek(struct dlList* list, int8_t pos) {
	struct dlNode* nodo = NULL;
	void *v = NULL;

	nodo = dlLgetpos(list, pos);
	if (nodo == NULL) {
		return NULL;
	}

	v = nodo->value;

	return v;
}

void dlLdelindx(struct dlList* list, int8_t pos) {
	struct dlNode* nodo = NULL;

	nodo = dlLgetpos(list, pos);
	if (nodo == NULL) {
		return;
	}

	/* reasignamos */
	if (pos == 0) { /* para el primer nodo */
		nodo->next->prev = NULL;
		list->ppo = nodo->next;
	}
	else if (pos == (list->numitems - 1)) { /* para el último nodo */
		nodo->prev->next = NULL;
	}
	else { /* para el resto de casos */
		nodo->prev->next = nodo->next;
		nodo->next->prev = nodo->prev;
	}

	free(nodo);
	list->numitems--;
}

void dlLdelete(struct dlList* list) {
	free(list);
}
