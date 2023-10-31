#ifndef __GENERICQUEUE_H__
#define __GENERICQUEUE_H__

#include <stdint.h> /* uint8_t */

struct gNode {
    void *value;
    struct gNode* next;
};

struct gQueue {
    struct gNode* ppo;
    struct gNode* fin;
    uint8_t numitems;
};

struct gQueue* gQinit();
void    gQdelete (struct gQueue* queue);
void    gQenqueue(struct gQueue* queue, void *v);
int8_t  gQisempty(struct gQueue* queue);
void   *gQdequeue(struct gQueue* queue);
uint8_t gQnumelem(struct gQueue* queue);

#endif /* __GENERICQUEUE_H__ */
