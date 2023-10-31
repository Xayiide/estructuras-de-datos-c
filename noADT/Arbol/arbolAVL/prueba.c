#include <stdio.h>
#include <stdlib.h> /* atoi, rand, srand */
#include <time.h>   /* time              */
#include "inc/AVL.h"


int main(int argc, char *argv[]) {
    int i;
    int v;
    int nn = 10;

    if (argc == 2) {
        nn = atoi(argv[1]);
    }

    arbavl *avl = creaAvl();

    srand(time(NULL));
    for (i = 0; i < nn; i++) {
        v = rand() % (256); /* max uint8 */
        inserta(avl, v);
    }

#ifndef VIS
    printf("Nodos insertados. Recorriendo...\n");
    if (balanceado(avl) == 0)
        printf("Árbol balanceado. Éxito\n");
    else
        printf("Árbol no balanceado. Fracaso\n");
#else
    imprimeAvl(avl);
#endif

    borraAvl(avl);

    return 0;
}

