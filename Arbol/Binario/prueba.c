#include <stdio.h>
#include "inc/arbBin.h"

int main(void) {
	struct arbbin *arbol = NULL;
	arbol = creaArbbin();

	inserta(arbol, 70);
	inserta(arbol, 30);
	inserta(arbol, 20);
	inserta(arbol, 40);
	inserta(arbol, 90);
	inserta(arbol, 80);
	inserta(arbol, 100);

	imprimeArbbin(arbol);


	return 0;
}

