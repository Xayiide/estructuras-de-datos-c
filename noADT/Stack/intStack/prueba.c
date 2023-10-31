#include <stdio.h>
#include <stdlib.h> /* free */
#include "inc/intstack.h"

int main(int argc, char** argv) {
	struct node_is* top = NULL;
	int dato = 0;
	
	push_is(&top, 1);
	push_is(&top, 2);
	push_is(&top, 3);

	dato = pop_is(&top);
	printf("El elemento cima es: %d\n", dato);
	push_is(&top, dato);

	if (isempty_is(&top) == 0) {
		printf("La pila no está vacía\n");
	}
	else {
		printf("La pila está vacía\n");
	}
	printf("Imprimimos la pila:\n");
	print_is(&top);

	free(top);

	return 0;
}
