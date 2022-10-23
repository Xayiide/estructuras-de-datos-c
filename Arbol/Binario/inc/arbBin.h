#ifndef _ARBBIN_H_
#define _ARBBIN_H_

#include <stdint.h>

typedef struct arbb  arbbin;
typedef struct arbbn abNodo;

arbbin *creaArbbin();
void    freeArbbin(arbbin*);
void    imprimeArbbin(arbbin*);

#endif

