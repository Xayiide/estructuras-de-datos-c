#include <stdio.h>
#include "inc/arbBin.h"

int main(void) {
	struct arbbin *arbol = NULL;
	struct abNodo *raiz, *n1, *n2, *n3;
	struct abNodo *n4, *n5, *n6;
	arbol = creaArbbin();

	raiz = creaAbnodo((uint8_t) 70);
	n2   = creaAbnodo((uint8_t) 30);
	n1   = creaAbnodo((uint8_t) 20);
	n3   = creaAbnodo((uint8_t) 40);
	n4   = creaAbnodo((uint8_t) 80);
	n5   = creaAbnodo((uint8_t) 90);
	n6   = creaAbnodo((uint8_t) 100);

	insertaNodo(arbol, raiz);
	insertaNodo(arbol, n1);
	insertaNodo(arbol, n2);
	insertaNodo(arbol, n3);
	insertaNodo(arbol, n4);
	insertaNodo(arbol, n5);
	insertaNodo(arbol, n6);
	

	return 0;
}

