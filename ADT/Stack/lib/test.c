#include <stdio.h>
#include "inc/stack.h"

static void memory_overwrite(stack_t stk)
{
    int a = 10;
    int b = 20;
    int c = 30;

    printf("a: %d -- %p\n", a, &a);
    printf("b: %d -- %p\n", b, &b);
    printf("c: %d -- %p\n", c, &c);

    stack_push(stk, &a);
    stack_push(stk, &b);
    stack_push(stk, &c);

    /* cuando se hace esta asignación, el valor de 'a' cambia a 30 */
    a = *(int *) stack_pop(stk);
    b = *(int *) stack_pop(stk);
    /* se asigna a c lo que hay en la posición de memoria del primer nodo de
     * la pila, donde se encontraba la dirección de 'a'. Como el valor de 'a'
     * ha cambiado y ahora vale 30, 'c' también vale 30 */
    c = *(int *) stack_pop(stk);

    printf("a b c: %d %d %d\n", a, b, c);
}

static void no_memory_overwrite(stack_t stk)
{
    int a = 10;
    int b = 20;
    int c = 30;

    printf("a: %d -- %p\n", a, &a);
    printf("b: %d -- %p\n", b, &b);
    printf("c: %d -- %p\n", c, &c);

    stack_push(stk, &a);
    stack_push(stk, &b);
    stack_push(stk, &c);

    /* esto podrían ser 3 variables diferentes y sería aún más claro */
    c = *(int *) stack_pop(stk);
    b = *(int *) stack_pop(stk);
    a = *(int *) stack_pop(stk);

    printf("a b c: %d %d %d\n", a, b, c);
}

int main()
{
    printf("\n\n\n");

    stack_t s;
    int a = 10;
    int b = 20;
    int c = 30;

    s = stack_new();
    printf("Stack creado en %p\n", s);

    memory_overwrite(s);
    printf("\n\n\n");
    no_memory_overwrite(s);

    return 0;
}

