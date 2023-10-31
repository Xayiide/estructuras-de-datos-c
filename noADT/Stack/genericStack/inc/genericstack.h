#ifndef __GENERICSTACK_H__
#define __GENERICSTACK_H_

#include <stdint.h> /* uint8_t */

struct gNode {
    void *value;
    struct gNode* next;
};

struct gStack {
    struct gNode* top;
    uint8_t numitems;
};

struct gStack* gSinit();
void    gSdelete (struct gStack* stack);
void    gSpush   (struct gStack* stack, void *v);
int8_t  gSisempty(struct gStack* stack);
void   *gSpop    (struct gStack* stack);
uint8_t gSnumelem(struct gStack* stack);


#endif /* __GENERICSTACK_H__ */
