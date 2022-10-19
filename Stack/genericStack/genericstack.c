#include <stdint.h> /* uint8_t */
#include <stdlib.h> /* malloc  */
#include <stdio.h>  /* perror  */
#include <errno.h>  /* errno   */
#include "inc/genericstack.h"

struct gStack* gSinit() {
    struct gStack* stack = NULL;
    stack = (struct gStack*) malloc(sizeof(struct gStack *));

    if (stack == 0) {
        errno = ENOMEM;
        perror("Error al obtener espacio en memoria (malloc)\n");
        return NULL;
    }
    else {
        stack->top      = NULL;
        stack->numitems = 0;
    }

    return stack;
}

void gSpush(struct gStack* stack, void* v) {
    struct gNode* node = NULL;
    node = (struct gNode*) malloc(sizeof(struct gNode*));

    if (node == 0) {
        errno = ENOMEM;
        perror("Error al obtener espacio de memoria (malloc)\n");
        return;
    }

    if (stack->numitems == 0) {
        node->next = NULL;
    } else {
        node->next = stack->top;
    }

    node->value = v;
    stack->top  = node;
    stack->numitems++;
}

int8_t gSisempty(struct gStack* stack) {
    return (stack->numitems == 0 ? 1 : 0);
}

void *gSpop(struct gStack* stack) {
    struct gNode* node = NULL;
    void *dato         = NULL;

    if (gSisempty(stack) == 1) {
        return ((void *) -1);
    }

    node = stack->top;
    dato = stack->top->value;

    stack->top = stack->top->next;
    free(node);

    stack->numitems--;

    return dato;
}

void gSdelete(struct gStack* stack) {
    free(stack);
}
