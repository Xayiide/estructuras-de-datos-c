#ifndef __INTQUEUE_H__
#define __INTQUEUE_H__

#include <stdint.h>

struct node_iq {
	uint8_t value;
	struct node_iq* next;
};

void enqueue_iq(struct node_iq** inicio, struct node_iq** fin, uint8_t v);
int8_t isempty_iq(struct node_iq** inicio, struct node_iq** fin);
int8_t dequeue_iq(struct node_iq** inicio, struct node_iq** fin);
void print_iq(struct node_iq** inicio, struct node_iq** fin);

#endif /* __INTQUEUE_H__ */
