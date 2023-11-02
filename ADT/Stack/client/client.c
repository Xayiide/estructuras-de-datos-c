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

    return 0;
}

