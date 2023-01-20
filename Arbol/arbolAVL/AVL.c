#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <errno.h>  /* errno   */
#include <stdio.h>

#include "inc/AVL.h"

static uint8_t  insertaNodo(nodoavl **, nodoavl *n);
static nodoavl *buscaNodo  (nodoavl *, uint8_t);
static void     borraNodo  (nodoavl *);
static void     imprimeNodo(nodoavl *);




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

    nodo->dcha   = nodo->izda = NULL;
    nodo->valor  = valor;
    nodo->altura = 0;

    res = insertaNodo(&(arb->raiz), nodo);
    if (res == 0)
        arb->numelem++;

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
        imprimeNodo(raiz);
        printf("}\n");
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
            res = insertaNodo(&(r->izda), nodo);
        }
        else { /* nodo->valor > r->valor */
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

static void imprimeNodo(nodoavl* n) {
    if (n->izda != NULL) {
        printf("%d -> %d;\n", n->valor, n->izda->valor);
        imprimeNodo(n->izda);
    }
    
    if (n->dcha != NULL) {
        printf("%d -> %d;\n", n->valor, n->dcha->valor);
        imprimeNodo(n->dcha);
    }
}





