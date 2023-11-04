#include <stdio.h>     /* test   */
#include <stdlib.h>    /* malloc */
#include "inc/stack.h"

#define stack stack_t

struct elem {
    void        *value;
    struct elem *next;
};

struct stack {
    int          count;
    struct elem *head;
};

stack stack_new(void)
{
    stack stk;

    stk = malloc(sizeof *(stk));
    if (stk == NULL)
        return NULL;

    stk->count = 0;
    stk->head  = NULL;

    return stk;
}

int stack_empty(stack stk)
{
    if (stk == NULL)
        return -1;
    return stk->count == 0;
}

void stack_push(stack stk, void *item)
{
    struct elem *node = NULL;

    if (stk == NULL)
        return;

    node = malloc(sizeof *(node));
    if (node == NULL)
        return;

    node->value = item;
    node->next  = stk->head;

    stk->head = node;
    stk->count++;
}

void *stack_pop(stack stk)
{
    void        *pop_value;
    struct elem *node;

    if (stk == NULL || stk->count == 0)
        return NULL;

    node      = stk->head;
    pop_value = node->value;

    stk->head = node->next;
    stk->count--;

    free(node);
    return pop_value;
}

void stack_free(stack *s)
{
    struct elem *t, *u;

    if (s == NULL)
        return;

    for (t = (*s)->head; t; t = u) {
        u = t->next;
        free(t);
    }
    free(*s);
}
