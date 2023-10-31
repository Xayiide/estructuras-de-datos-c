#include <stdio.h>
#include "inc/dobleenlaz.h"


int main(int argc, char** argv) {
	struct dlList* lista;
	lista = dlLinit();

	void* elem;
	char  s[] = "hola\0";
	int   i   = 10;
	float f   = 20.24;
	char  c   = 'a';

	dlLinsert(lista, &s);
	dlLinsert(lista, &i);
	dlLinsert(lista, &f);
	dlLinsert(lista, &c);
	dlLimprime(lista); /* c f i s */

	printf("\n");
	elem = dlLpeek(lista, 0);
	printf("elemento 0: %c\n", *(char *) elem);
	elem = dlLpeek(lista, 1);
	printf("elemento 1: %f\n", *(float *) elem);
	elem = dlLpeek(lista, 2);
	printf("elemento 2: %d\n", *(int *) elem);
	elem = dlLpeek(lista, 3);
	printf("elemento 4: %s\n", (char *) elem);

	/* accesos no permitidos */
	elem = dlLpeek(lista, 4);
	elem = dlLpeek(lista, -1);


	printf("\n");
	printf("Eliminamos el elemento 1\n");
	dlLdelindx(lista, 1);
	dlLimprime(lista);

	printf("\n");
	printf("Eliminamos el elemento 0\n");
	dlLdelindx(lista, 0);
	dlLimprime(lista);

	printf("\n");
	printf("Eliminamos el elemento 1\n");
	dlLdelindx(lista, 1);
	dlLimprime(lista);

	dlLdelete(lista);

	return 0;
}
