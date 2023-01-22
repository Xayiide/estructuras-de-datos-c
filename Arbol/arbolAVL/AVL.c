#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <errno.h>  /* errno   */
#include <stdio.h>

#include "inc/AVL.h"

static uint8_t  insertaNodo(nodoavl **, nodoavl *n);
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
        balancea(nodo);
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

void balancea(nodoavl *nodo) {
    int8_t balance;
    uint8_t altizda, altdcha;

    while (nodo != NULL) {
        altizda = altura(nodo->izda);
        altdcha = altura(nodo->dcha);
        balance = altizda - altdcha;
        nodo->altura  = 1 + max(altizda, altdcha);
        if (balance <= -2) { /* subarbol dcho desbalanceado */

        }

        else if (balance >= 2) { /* subarbol izdo desbalanceado */

        }
        /* actualizar balance */
        nodo->balance = balance;
        nodo = nodo->padre;
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






