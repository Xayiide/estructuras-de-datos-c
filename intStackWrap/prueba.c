#include <stdio.h>
#include "inc/intstackwrap.h"

int main(int argc, char** argv) {
	struct intstack* stack_1;
	stack_1 = init_is();

	if (stack_1 == NULL) {
		printf("Error creando el stack. Abortando.\n");
		return -1;
	}

	pop_is(stack_1);
	push_is(stack_1, 10);
	push_is(stack_1, 20);
	

	if (isempty_is(stack_1) == 0) {
		printf("La pila no está vacía\n");
	}
	else {
		printf("La pila está vacía\n");
	}

	printf("Imprimimos la pila:\n");
	print_is(stack_1);

	return 0;
}
