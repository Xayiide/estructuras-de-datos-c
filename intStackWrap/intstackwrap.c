#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <stdio.h>  /* perror  */
#include <errno.h>  /* errno   */
#include "inc/intstackwrap.h"


struct intstack* init_is() {
	struct intstack* stack = NULL;
	stack = (struct intstack*) malloc(sizeof(struct intstack));

	/* comprueba si el heap está lleno */
	if (stack == 0) {
		errno = ENOMEM;
		perror("Error al obtener espacio en memoria (malloc)\n");
		return NULL;
	}
	else {
		stack->top      = NULL;
		stack->numitems = 0;
	}

	return stack;
}

void push_is(struct intstack* stack, uint8_t v) {
	struct node_is* node = NULL;
	node = (struct node_is*) malloc(sizeof(struct node_is));

	/* check if the heap is full */
	if (node == 0) {
		errno = ENOMEM;
		perror("Error al obtener espacio en memoria (malloc)\n");
		return;
	}

	if (stack->numitems == 0) {
		node->next = NULL;
	}
	else {
		node->next = stack->top;
	}

	node->value = v;
	stack->top  = node;
	stack->numitems++;

}

int8_t isempty_is(struct intstack* stack) {
	return (stack->numitems == 0 ? 1 : 0);
}

int8_t pop_is(struct intstack* stack) {
	int8_t dato;
	struct node_is* nodo; /* necesario xa liberar la memoria de la cima */
	
	if (isempty_is(stack) == 1) {
		return -1;
	}
	
	nodo = stack->top;
	dato = stack->top->value;

	stack->top = stack->top->next;
	free(nodo);

	stack->numitems--;

	return dato;
}


void print_is(struct intstack* stack) {
	uint8_t i= 0;
	struct node_is* nodo = NULL;

	if (isempty_is(stack) == 1) {
		return;
	}

	nodo = stack->top;
	printf("Top: 0x%p\n", stack->top);
	for (i = 0; i < stack->numitems; i++) {
		printf("[0x%p -> 0x%p | %3hhu]\n", nodo, nodo->next, nodo->value);
		nodo = nodo->next;
	}
}

uint8_t numelem_is(struct intstack* stack) {
	return stack->numitems;
}
