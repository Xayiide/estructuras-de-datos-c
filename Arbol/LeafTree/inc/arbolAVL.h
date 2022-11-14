#ifndef _ARBOLAVL_H_
#define _ARBOLAVL_H_

#include <stdint.h>




typedef struct {
	struct nodoavl *izda;
	struct nodoavl *dcha;
	uint8_t  valor;
	uint8_t  altura;
} nodoavl ;

typedef struct {
	nodoavl *raiz;
	uint8_t  numelem;
} arbolavl;

arbolavl *creaAVL();
void      borraAVL(arbolavl *);
//struct nodoavl  *creaAVLNodo(uint8_t);

//void borraArbolAVL   (struct arbolavl*);
//void imprimeArbolAVL (struct arbolavl*);
//void recorreArbolAVL (struct arbolavl*);


#endif
