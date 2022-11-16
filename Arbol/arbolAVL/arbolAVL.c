#include <errno.h>  /* errno   */
#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <stdio.h>  /* perror  */


#include "inc/arbolAVL.h"

arbolavl *creaAVL() {
	arbolavl *arbol = NULL;
	arbol = malloc(sizeof(arbolavl));

	if (arbol == NULL) {
		errno = ENOMEM;
		perror("creaAVL.\n");
		return NULL;
	}

	arbol->raiz    = NULL;
	arbol->numelem = 0;

	return arbol;
}

