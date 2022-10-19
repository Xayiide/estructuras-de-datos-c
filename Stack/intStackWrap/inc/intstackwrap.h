#ifndef __INTSTACKWRAP_H__
#define __INTSTACKWRAP_H__

#include <stdint.h>

struct node_is {
	int8_t value;
	struct node_is* next;
};

struct intstack {
	struct  node_is* top;
	uint8_t numitems;
};


struct intstack* init_is();
void    delete_is (struct intstack* stack);
void    push_is   (struct intstack* stack, uint8_t v);
int8_t  isempty_is(struct intstack* stack);
int8_t  pop_is    (struct intstack* stack);
void    print_is  (struct intstack* stack);
uint8_t numelem_is(struct intstack* stack);


#endif /* __INTSTACKWRAP_H__ */

