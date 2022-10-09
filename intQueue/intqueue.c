#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <stdio.h>  /* perror  */
#include <errno.h>  /* errno   */
#include "inc/intqueue.h"



void enqueue_iq(struct node_iq** inicio, struct node_iq** fin, uint8_t v) {
	struct node_iq* node = NULL;
	node = (struct node_iq*) malloc(sizeof(struct node_iq));

	/* comprueba si el heap está lleno */
	if (node == 0) {
		errno = ENOMEM;
		perror("Error al obtener espacio en memoria (malloc)\n");
		return;
	}

	node->value = v;

	/* si la cola está vacía */
	if (*inicio == NULL && *fin == NULL) {
		*inicio = node;
		*fin    = node;
	}
	/* sólo actualizamos el final */
	else {
		(*fin)->next = node;
		*fin = node;
	}
}

int8_t isempty_iq(struct node_iq** inicio, struct node_iq** fin) {
	if (*inicio == NULL && *fin == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

int8_t dequeue_iq(struct node_iq** inicio, struct node_iq** fin) {
	struct node_iq* node;
	int8_t dato;

	/* stack underflow */
	if (isempty_iq(inicio, fin) == 1) {
		printf("Error: la pila está vacía\n");
		return -1;
	}

	node    = *inicio;

	dato    = (*inicio)->value;
	*inicio = (*inicio)->next;

	/* se ha vaciado la lista */
	if (*inicio == NULL) {
		*fin = NULL;
	}

	free(node);

	return dato;
}

void print_iq(struct node_iq** inicio, struct node_iq** fin) {
	int8_t dato = 0;
	if (isempty_iq(inicio, fin) == 0) {
		printf("[   | 0x%08X]", (*inicio)->next);
		dato = dequeue_iq(inicio, fin);
		printf("\r[%03hhu\n", dato);
		print_iq(inicio, fin);
		printf("encolando");
		enqueue_iq(inicio, fin, dato);
	}
}
