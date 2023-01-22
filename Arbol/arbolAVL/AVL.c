#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <errno.h>  /* errno   */
#include <stdio.h>

#include "inc/AVL.h"

static uint8_t  insertaNodo(nodoavl **, nodoavl *n);
static void     balancea   (arbavl *, nodoavl *);
static nodoavl *buscaNodo  (nodoavl *, uint8_t);
static void     borraNodo  (nodoavl *);
static void     visNodo    (nodoavl *);
static void     imprimeNodo(nodoavl *);
static void     recorreNodo(nodoavl*, ordenRec);
static void     recorrePre (nodoavl *);
static void     recorreCentral(nodoavl *);
static void     recorrePost(nodoavl *);
static uint8_t  altura(nodoavl *);
static int8_t   max(int8_t, int8_t);
static void     rotIzda(arbavl *, nodoavl *);
static void     rotDcha(arbavl *, nodoavl *);



arbavl *creaAvl() {
    arbavl *arbol = NULL;
    arbol = malloc(sizeof(arbavl));

    if (arbol == NULL) {
        errno = ENOMEM;
        perror("creaAvl\n");
        return NULL;
    }

    arbol->raiz    = NULL;
    arbol->numelem = 0;

    return arbol;
}

nodoavl *buscaValor(arbavl *arb, uint8_t v) {
    nodoavl *nodo = NULL;

    if (arb == NULL) {
        printf("El árbol es nulo.\n");
        return NULL;
    }

    nodo = arb->raiz;
    if (nodo == NULL) {
        printf("El árbol está vacío.\n");
        return NULL;
    }

    nodo = buscaNodo(nodo, v);

    return nodo;
}

uint8_t inserta(arbavl *arb, uint8_t valor) {
    uint8_t res;
    nodoavl *nodo = malloc(sizeof(nodoavl));

    if (nodo == NULL) {
        errno = ENOMEM;
        perror("insertaNodo\n");
        return 1;
    }

    nodo->dcha    = nodo->izda = NULL;
    nodo->valor   = valor;
    nodo->balance = 0;
    // nodo->altura = 0; /* Se hace al balancear los nodos */

    res = insertaNodo(&(arb->raiz), nodo);
    if (res == 0) {
        arb->numelem++;
        balancea(arb, nodo);
    }
    else {
        free(nodo);
    }

    return res;
}

void borraAvl(arbavl *arb) {
    nodoavl *raiz= NULL;

    if (arb == NULL) {
        printf("Árbol nulo.\n");
        return;
    }

    raiz = arb->raiz;
    if (raiz == NULL)
        printf("El árbol está vacío.\n");
    else
        borraNodo(raiz);

    free(arb);
}

void imprimeAvl(arbavl *arb) {
    nodoavl *raiz = NULL;
    raiz = arb->raiz;

    if (raiz != NULL) {
        printf("digraph {\n");
        visNodo(raiz);
        printf("}\n");
    }
    else {
        printf("El árbol está vacío.\n");
    }
}

void recorreAvl(arbavl *arb, ordenRec orden) {
    nodoavl* nodo = arb->raiz;

    if (nodo != NULL) {
        recorreNodo(nodo, orden);
        printf("\n");
    }
    else {
        printf("El árbol está vacío.\n");
    }
}





static uint8_t insertaNodo(nodoavl **raiz, nodoavl *nodo) {
    nodoavl *r  = *raiz;
    uint8_t res = 0;

    if (r == NULL) {
        *raiz = nodo; /* insertamos */
        res   = 0;
    }
    else {
        if (nodo->valor == r->valor) {
            printf("El valor %d ya existe en el árbol.\n", nodo->valor);
            res = 1;
        }
        else if (nodo->valor < r->valor) {
            nodo->padre = r;
            res = insertaNodo(&(r->izda), nodo);
        }
        else { /* nodo->valor > r->valor */
            nodo->padre = r;
            res = insertaNodo(&(r->dcha), nodo);
        }
    }

    return res;
}

/*
 * Hay 4 casos para balancear:
 * 1. 2 nodos descienden hacia la izda -> RR(nodo)
 * 2. Zig-Zag (izda-dcha) -> LR(nodo->iz) RR(nodo)
 * 3. Zag-Zig (dcha-izda) -> RR(nodo->de) LR(nodo)
 * 4. 2 nodos descienden hacia la dcha -> LR(nodo)
 */
static void balancea(arbavl *arb, nodoavl *nodo) {
    int8_t balance;
    uint8_t altizda, altdcha;

    while (nodo != NULL) {
        altizda = altura(nodo->izda);
        altdcha = altura(nodo->dcha);
        balance = altizda - altdcha;
        nodo->altura  = 1 + max(altizda, altdcha);
        if (balance >= 2) { /* subarbol izdo desbalanceado */
            if (altura(nodo->izda->izda) < altura(nodo->izda->dcha)) { /* 2 */
                rotIzda(arb, nodo->izda);
                rotDcha(arb, nodo);
            }
            else { /* 1 */
                rotDcha(arb, nodo);
            }
        }
        else if (balance <= -2) { /* subarbol dcho desbalanceado */
            if (altura(nodo->dcha->dcha) < altura(nodo->dcha->izda)) { /* 3 */
                rotDcha(arb, nodo->dcha);
                rotIzda(arb, nodo);
            }
            else { /* 4 */
                rotIzda(arb, nodo);
            }
        }

        /* actualizar balance */
        nodo->balance = balance;
        nodo = nodo->padre;
    }
}

static nodoavl *buscaNodo(nodoavl *nodo, uint8_t v) {
    struct nodoavl *n;

    if (nodo == NULL) {
        printf("El valor buscado no existe.\n");
        n = NULL;
    }
    else if (v == nodo->valor) {
        n = nodo;
    }
    else if (v < nodo->valor) {
        n = buscaNodo(nodo->izda, v);
    }
    else if (v > nodo->valor) {
        n = buscaNodo(nodo->dcha, v);
    }

    return n;
}

static void borraNodo(nodoavl *nodo) {
    if (nodo != NULL) {
        borraNodo(nodo->izda);
        borraNodo(nodo->dcha);
        free(nodo);
    }
}

static void visNodo(nodoavl* nodo) {
    if (nodo->izda != NULL) {
        printf("%d -> %d;\n", nodo->valor, nodo->izda->valor);
        visNodo(nodo->izda);
    }
    
    if (nodo->dcha != NULL) {
        printf("%d -> %d;\n", nodo->valor, nodo->dcha->valor);
        visNodo(nodo->dcha);
    }
}

static void imprimeNodo(nodoavl *nodo) {
    printf("|v%d|a%d|b%d", nodo->valor, nodo->altura, nodo->balance);
    if (nodo->padre != NULL)
        printf("|p%d", nodo->padre->valor);
    printf("|\n");
}

static void recorreNodo(nodoavl* nodo, ordenRec orden) {
    switch(orden) {
    case PREORDEN:
        recorrePre(nodo);
        break;
    case ORDENCENTRAL:
        recorreCentral(nodo);
        break;
    case POSTORDEN:
        recorrePost(nodo);
        break;
    default:
        printf("Error: recorreNodo (default)\n");
        break;
    }
}

static void recorrePre(nodoavl *nodo) {
    imprimeNodo(nodo);

    if (nodo->izda != NULL) {
        recorrePre(nodo->izda);
    }
    
    if (nodo->dcha != NULL) {
        recorrePre(nodo->dcha);
    }
}

static void recorreCentral(nodoavl *nodo) {
    if (nodo->izda != NULL) {
        recorreCentral(nodo->izda);
    }
    
    imprimeNodo(nodo);

    if (nodo->dcha != NULL) {
        recorreCentral(nodo->dcha);
    }
}

static void recorrePost(nodoavl *nodo) {
    if (nodo->izda != NULL) {
        recorrePost(nodo->izda);
    }

    if (nodo->dcha != NULL) {
        recorrePost(nodo->dcha);
    }

    imprimeNodo(nodo);
}

static uint8_t altura(nodoavl *nodo) {
    if (nodo == NULL) {
        return (-1);
    }
    else {
        return nodo->altura;
    }
}

static int8_t max(int8_t a, int8_t b) {
    return (a >= b ? a : b);
}

static void rotIzda(arbavl *arb, nodoavl *nodo) {
    nodoavl *aux = nodo->dcha; /* siempre existe? */
    aux->padre   = nodo->padre; /* el nodo de su derecha toma su lugar */

    if (aux->padre == NULL) {
        arb->raiz = aux; /* Nueva raiz */
    }
    else {
        if (aux->padre->izda == nodo)
            aux->padre->izda = aux;
        else if (aux->padre->dcha == nodo)
            aux->padre->dcha = aux;
    }

    nodo->dcha = aux->izda;

    if (nodo->dcha != NULL)
        nodo->dcha->padre = nodo;

    aux->izda    = nodo;
    nodo->padre  = aux;
    nodo->altura = 1 + max(altura(nodo->izda), altura(nodo->dcha));
    aux->altura  = 1 + max(altura(aux->izda), altura(aux->dcha));
}

static void rotDcha(arbavl *arb, nodoavl *nodo) {
    nodoavl *aux = nodo->izda;
    aux->padre   = nodo->padre;

    if (aux->padre == NULL) {
        arb->raiz = aux;
    }
    else {
        if (aux->padre->izda == nodo)
            aux->padre->izda = aux;
        else if (aux->padre->dcha == nodo)
            aux->padre->dcha = aux;
    }

    nodo->izda = aux->dcha;

    if (nodo->izda != NULL)
        nodo->izda->padre = nodo;

    aux->dcha    = nodo;
    nodo->padre  = aux;
    nodo->altura = 1 + max(altura(nodo->izda), altura(nodo->dcha));
    aux->altura  = 1 + max(altura(aux->izda), altura(aux->dcha));
}




