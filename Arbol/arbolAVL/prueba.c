#include <stdio.h>
#include "inc/arbolAVL.h"


int main(void) {
	arbolavl *arbol = NULL;
	arbol = creaAVL();

	insertaNodo(arbol, 100);
	insertaNodo(arbol, 35);
	insertaNodo(arbol, 10);
	insertaNodo(arbol, 15);
	insertaNodo(arbol, 70);
	insertaNodo(arbol, 1);

	imprimeArbolAVL(arbol);

	borraAVL(arbol);

	return 0;

}
