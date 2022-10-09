#include <stdio.h>
#include "inc/intqueue.h"

int main(int argc, char** argv) {
	struct node_iq* ppo = NULL;
	struct node_iq* fin = NULL;
	int dato = 0;
	
	enqueue_iq(&ppo, &fin, 1);
	enqueue_iq(&ppo, &fin, 2);
	enqueue_iq(&ppo, &fin, 3);

	dato = dequeue_iq(&ppo, &fin);
	printf("El elemento del ppo es: %d\n", dato);
	enqueue_iq(&ppo, &fin, dato);

	if (isempty_iq(&ppo, &fin) == 0)
		printf("La cola no está vacía\n");
	else
		printf("La cola está vacía\n");

	printf("Imprimimos la cola:\n");
	print_iq(&ppo, &fin);

	return 0;
}
