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
    stack s;

    s = malloc(sizeof *(s));
    if (s == NULL)
        return NULL;

    s->count = 0;
    s->head  = NULL;

    return s;
}

int stack_empty(stack s)
{
    if (s == NULL)
        return -1;
    return s->count == 0;
}

void stack_push(stack s, void *e)
{
    struct elem *i = NULL;

    if (s == NULL)
        return;

    s = malloc(sizeof *(s));
    if (s == NULL)
        return;

    i->value = e;
    i->next  = s->head;

    s->head  = i;
    s->count++;
}

void *stack_pop(stack s)
{
    void        *x;
    struct elem *i;

    if (s == NULL || s->count == 0)
        return NULL;

    i = s->head;
    s->head = i->next;
    s->count--;

    x = i->value;

    free(i);
    return x;
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
