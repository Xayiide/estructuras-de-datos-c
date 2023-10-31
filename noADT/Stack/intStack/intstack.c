#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <stdio.h>  /* perror  */
#include <errno.h>  /* errno   */
#include "inc/intstack.h"

void push_is(struct node_is** top, uint8_t v) {
	struct node_is* node = NULL;
	node = (struct node_is*) malloc(sizeof(struct node_is));

	/* check if the heap is full */
	if (node == 0) {
		errno = ENOMEM;
		perror("Error al obtener espacio en memoria (malloc)\n");
		return;
	}

	node->value = v;
	node->next  = *top;

	*top = node;
}

int8_t isempty_is(struct node_is** top) {
	if (*top == NULL) /* top apunta a NULL? */
		return 1;
	else 
		return 0;
}

int8_t pop_is(struct node_is** top) {
	int8_t dato;
	struct node_is* node;

	/* stack underflow */
	if (*top == NULL) {
		printf("Error: la pila está vacía\n");
		return -1;
	}
	node = *top;

	dato = (*top)->value;
	*top = (*top)->next;

	free(node);

	return dato;
}

void print_is(struct node_is** top) {
	int8_t dato = 0;
	if (isempty_is(top) == 0) {
		printf("[   | 0x%p]", (*top)->next);
		dato = pop_is(top);
		printf("\r[%03hhu\n", dato);
		print_is(top);
		push_is(top, dato);
	}
}
