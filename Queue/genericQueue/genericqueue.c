#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <stdio.h>  /* perror  */
#include <errno.h>  /* errno   */
#include "inc/genericqueue.h"


struct gQueue* gQinit() {
    struct gQueue* queue = NULL;
    queue = (struct gQueue*) malloc(sizeof(struct gQueue));

    if (queue == 0) {
        errno = ENOMEM;
        perror("Error al obtener espacio en memoria (malloc)\n");
        return NULL;
    }
    else {
        queue->ppo      = NULL;
        queue->fin      = NULL;
        queue->numitems = 0;
    }

    return queue;
}

void gQenqueue(struct gQueue* queue, void* v) {
    struct gNode* node = NULL;
    node = (struct gNode*) malloc(sizeof(struct gNode*));

    if (node == 0) {
        errno = ENOMEM;
        perror("Error al obtener espacio en memoria (malloc)\n");
        return;
    }

    if (queue->numitems == 0) {
        queue->ppo = node;
        queue->fin = node;
    }
    else {
        queue->fin->next = node;
        queue->fin       = node;
    }

    node->value = v;
    node->next  = NULL;
    queue->numitems++;
}

int8_t gQisempty(struct gQueue* queue) {
    return (queue->numitems == 0 ? 1 : 0);
}

void *gQdequeue(struct gQueue* queue) {
    struct gNode* node = NULL;
    void *dato         = NULL;

    if (gQisempty(queue) == 1) {
        return ((void *) -1);
    }

    node = queue->ppo;
    dato = queue->ppo->value;

    queue->ppo = queue->ppo->next;

    queue->numitems--;

    /* se ha vaciado la pila */
    if (gQisempty(queue) == 1) {
        queue->fin = NULL;
    }

    free(node);

    return dato;
}

uint8_t gQnumelem(struct gQueue* queue) {
    return queue->numitems;
}

void gQdelete(struct gQueue* queue) {
    free(queue);
}
