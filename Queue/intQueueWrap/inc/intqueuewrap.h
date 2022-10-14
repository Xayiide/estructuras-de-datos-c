#ifndef __INTQUEUEWRAP_H__
#define __INTQUEUEWRAP_H__

#include <stdint.h>

struct node_iq {
	uint8_t value;
	struct node_iq* next;
};

struct intqueue {
	struct  node_iq* inicio;
	struct  node_iq* fin;
	uint8_t numitems;
};


struct intqueue* init_iq();
void    enqueue_iq(struct intqueue* queue, uint8_t v);
int8_t  isempty_iq(struct intqueue* queue);
int8_t  dequeue_iq(struct intqueue* queue);
void    print_iq  (struct intqueue* queue);
uint8_t numelem_iq(struct intqueue* queue);

#endif /* __INTQUEUEWRAP_H__ */
