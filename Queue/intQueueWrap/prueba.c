#include <stdio.h>
#include "inc/intqueuewrap.h"

int main(int argc, char** argv) {

	struct intqueue* queue_1;
	queue_1 = init_iq();

	if (queue_1 == NULL) {
		printf("Error creando el stack. Abortando.\n");
		return -1;
	}

	dequeue_iq(queue_1);
	enqueue_iq(queue_1, 10);
	enqueue_iq(queue_1, 20);
	enqueue_iq(queue_1, 30);
	enqueue_iq(queue_1, 40);
	dequeue_iq(queue_1);
	enqueue_iq(queue_1, 50);
	dequeue_iq(queue_1);

	if (isempty_iq(queue_1) == 0) {
		printf("La cola no está vacía\n");
	}
	else {
		printf("La cola está vacía\n");
	}

	printf("Imprimimos la cola:\n");
	print_iq(queue_1);

	delete_iq(queue_1);

	return 0;
}
