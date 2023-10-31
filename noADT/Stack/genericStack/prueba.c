#include <stdio.h>
#include "inc/genericstack.h"


int main(int argc, char **argv) {
    struct gStack* genS;
    genS = gSinit();

    void *pop;

    int i = 666;
    float j = 66.6;
    char k = 'a';

    gSpush(genS, &i);
    gSpush(genS, &j);
    gSpush(genS, &k);

    pop = gSpop(genS);
    printf("pop: %c\n", *((char *) pop));
    pop = gSpop(genS);
    printf("pop: %f\n", *((float *) pop));
    pop = gSpop(genS);
    printf("pop: %d\n", *((int *) pop));

    gSdelete(genS);

    return 0;
}
