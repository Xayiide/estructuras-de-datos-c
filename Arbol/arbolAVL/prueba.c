#include <stdio.h>
#include "inc/AVL.h"


int main(void) {
    arbavl *avl = creaAvl();

    inserta(avl, 100);
    inserta(avl, 35);
    inserta(avl, 10);
    inserta(avl, 5);
    inserta(avl, 60);
    inserta(avl, 75);

    imprimeAvl(avl);

    borraAvl(avl);

    return 0;
}

