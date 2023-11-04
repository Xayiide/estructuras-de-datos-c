#include <stdio.h>

#include "inc/stack.h"

int main()
{
    stack_t s;

    int a = 10;
    int b = 20;
    int c = 30;

    s = stack_new();

    stack_push(s, &a);
    stack_push(s, &b);
    stack_push(s, &c);

    c = *(int *) stack_pop(s);
    b = *(int *) stack_pop(s);
    a = *(int *) stack_pop(s);

    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);

    stack_free(&s);

    return 0;
}

