#include <stdio.h>
#include "inc/genericqueue.h"


int main(int argc, char** argv) {

    struct gQueue* genQ;
    genQ = gQinit();

    void *pop;

    int i = 10;
    float j = 20.42;
    char k = 'a';

    gQenqueue(genQ, &i);
    gQenqueue(genQ, &j);
    gQenqueue(genQ, &k);


    pop = gQdequeue(genQ);
    printf("dequeue: %d\n", *((int *)pop));
    pop = gQdequeue(genQ);
    printf("dequeue: %f\n", *((float *)pop));
    pop = gQdequeue(genQ);
    printf("dequeue: %c\n", *((char *)pop));


    return 0;
}
