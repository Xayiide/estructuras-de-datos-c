#ifndef _ARBBIN_H_
#define _ARBBIN_H_

#include <stdint.h>

enum ordenRec {
	ORDENCENTRAL = 1,
	PREORDEN     = 2,
	POSTORDEN    = 3
};

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
void    borraArbbin     (struct arbbin*);
void    imprimeArbbin   (struct arbbin*);
void    recorreArbbin   (struct arbbin*, enum ordenRec orden);
uint8_t inserta         (struct arbbin*, uint8_t);

#endif

