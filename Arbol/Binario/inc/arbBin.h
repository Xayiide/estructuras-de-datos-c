#ifndef _ARBBIN_H_
#define _ARBBIN_H_

#include <stdint.h>


struct abNodo {
	struct abNodo *izda;
	struct abNodo *dcha;
    uint8_t valor;
};

struct arbbin {
    struct abNodo *raiz;
    uint8_t numelem;
};

struct arbbin *creaArbbin();
struct abNodo *creaAbnodo(uint8_t v);
void    freeArbbin      (struct arbbin*);
void    imprimeArbbin   (struct arbbin*);
void    recorreCentral  (struct arbbin*);
void    recorrePreorden (struct arbbin*);
void    recorrePostorden(struct arbbin*);
uint8_t inserta(struct arbbin*, uint8_t);

#endif

