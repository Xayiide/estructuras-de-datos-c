#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <stdio.h>  /* perror  */
#include <errno.h>  /* errno   */
#include "inc/intqueuewrap.h"


struct intqueue* init_iq() {
	struct intqueue* queue = NULL;
	queue = (struct intqueue*) malloc(sizeof(struct intqueue));

	/* heap full */
	if (queue == 0) {
		errno = ENOMEM;
		perror("Error al obtener esacio en memoria (malloc)\n");
		return NULL;
	}
	else {
		queue->inicio   = NULL;
		queue->fin      = NULL;
		queue->numitems = 0;
	}
	return queue;
}

void enqueue_iq(struct intqueue* queue, uint8_t v) {
	struct node_iq* node = NULL;
	node = (struct node_iq*) malloc(sizeof(struct node_iq));

	if (node == 0) {
		errno = ENOMEM;
		perror("Error al obtener espacio en memoria (malloc)\n");
		return;
	}


	/* Comprobamos si la cola está vacía */
	if (queue->numitems == 0) {
		queue->inicio = node;
		queue->fin    = node;
	}
	else {
		queue->fin->next = node;
		queue->fin       = node;
	}
	node->value = v;
	node->next  = NULL;
	queue->numitems++;
}

int8_t isempty_iq(struct intqueue* queue) {
	return (queue->numitems == 0 ? 1 : 0);
}

int8_t dequeue_iq(struct intqueue* queue) {
	struct node_iq* node = NULL;
	uint8_t dato = 0;

	if (isempty_iq(queue) == 1) {
		return -1;
	}

	node = queue->inicio;
	dato = queue->inicio->value;

	queue->inicio = queue->inicio->next;

	queue->numitems--;

	/* se ha vaciado la cola */
	if (isempty_iq(queue) == 1) {
		queue->fin = NULL;
	}

	free(node);

	return dato;
}	

void print_iq(struct intqueue* queue) {
	uint8_t i;
	struct node_iq* nodo = NULL;

	if (isempty_iq(queue) == 1) {
		return;
	}

	nodo = queue->inicio;
	printf("Inicio: 0x%p\n", queue->inicio);
	printf("Final : 0x%p\n", queue->fin);
	for (i = 0; i < queue->numitems; i++) {
		printf("[0x%p -> 0x%p | %3hhu]\n", nodo, nodo->next, nodo->value);
		nodo = nodo->next;
	}
}

uint8_t numelem_iq(struct intqueue* queue) {
	return queue->numitems;
}

