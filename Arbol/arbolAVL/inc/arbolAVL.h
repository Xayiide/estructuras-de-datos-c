#ifndef _ARBOLAVL_H_
#define _ARBOLAVL_H_

#include <stdint.h>

typedef enum {
	COMPLETO   = 1, /* Nodo interior completo   */
	INCOMPLETO = 2, /* Nodo interior incompleto */
	HOJA       = 3  /* Nodo hoja                */
} tiponodo;


typedef struct nodoavl nodoavl;
struct nodoavl {
	struct nodoavl *izda;
	struct nodoavl *dcha;
	uint8_t  valor;
	uint8_t  altura;
};

typedef struct {
	nodoavl *raiz;
	uint8_t  numelem;
} arbolavl;

arbolavl *creaAVL     ();
void      borraAVL    (arbolavl *);
uint8_t   insertaNodo (arbolavl *, uint8_t);

void imprimeArbolAVL  (arbolavl*);

tiponodo tipoNodo     (nodoavl *);
uint8_t  altura       (nodoavl *);
int8_t   factorBalance(nodoavl *);


#endif
