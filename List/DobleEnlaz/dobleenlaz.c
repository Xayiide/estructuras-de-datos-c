#include <stdint.h>
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
		list->ppo  = nodo;
	}

	nodo->prev = NULL;
	nodo->value = v;
	list->numitems++;
}

int8_t dlLisempty(struct dlList* list) {
	return (list->numitems == 0 ? 1 : 0);
}

void *dlLpeek(struct dlList* list, int8_t pos) {
	struct dlNode* nodo = NULL;
	int8_t i;
	void *v = NULL;

	if (pos > (list->numitems - 1)) {
		printf("Índice (%3hhu) fuera de rango\n", pos);
		return ((void *) 0);
	}

	nodo = list->ppo;
	for (i = 0; i < pos + 1; i++) {
		v = nodo->value;
	}

}

uint8_t dlLnumelem(struct dlList* list) {
	return list->numitems;
}
