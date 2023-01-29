#ifndef _AVL_H_
#define _AVL_H_

#include <stdint.h>


typedef enum {
    ORDENCENTRAL = 1,
    PREORDEN     = 2,
    POSTORDEN    = 3
} ordenRec;

typedef enum {
    COMPLETO   = 1,
    INCOMPLETO = 2,
    HOJA       = 3
} tipoNodo;

typedef struct nodoavl nodoavl;
struct nodoavl {
    nodoavl *izda;
    nodoavl *dcha;
    nodoavl *padre;
    uint8_t  valor;
    uint8_t   altura;
    int8_t   balance;
};

typedef struct {
    nodoavl *raiz;
    uint8_t  numelem;
} arbavl;

arbavl  *creaAvl();
nodoavl *buscaValor(arbavl *, uint8_t); /* devuelve punt. a nodo con valor v */
uint8_t inserta    (arbavl *, uint8_t);
uint8_t borra      (arbavl *, uint8_t);
void borraAvl      (arbavl *);
void imprimeAvl    (arbavl *);
void recorreAvl    (arbavl *, ordenRec);
int8_t balanceado  (arbavl *);
void rotaIzda      (nodoavl *);
void rotaDcha      (nodoavl *);


tipoNodo tipoavl(nodoavl *);


#endif
