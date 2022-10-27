#include <stdio.h>
#include "inc/arbBin.h"

int main(void) {
	struct arbbin *arbol = NULL;
	arbol = creaArbbin();

	inserta(arbol, 60); /* F */
	inserta(arbol, 20); /* B */
	inserta(arbol, 10); /* A */
	inserta(arbol, 40); /* D */
	inserta(arbol, 30); /* C */
	inserta(arbol, 50); /* E */
	inserta(arbol, 70); /* G */
	inserta(arbol, 90); /* I */
	inserta(arbol, 80); /* H */
	

	imprimeArbbin(arbol);

#ifndef VIS
	printf("Preorden:      ");
	recorreArbbin(arbol, PREORDEN);
	printf("Orden central: ");
	recorreArbbin(arbol, ORDENCENTRAL);
	printf("Postorden:     ");
	recorreArbbin(arbol, POSTORDEN);
#endif

	borraArbbin(arbol);

	return 0;
}

