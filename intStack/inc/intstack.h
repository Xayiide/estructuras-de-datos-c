#ifndef __INTSTACK_H__
#define __INTSTACK_H__

#include <stdint.h>

struct node_is{
	int8_t value;
	struct node_is* next;
};

void push_is(struct node_is** top, uint8_t v);
int8_t isempty_is(struct node_is** top);
int8_t pop_is(struct node_is** top);
void print_is(struct node_is** top);


#endif /* __INTSTACK_H__ */
