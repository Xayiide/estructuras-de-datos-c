#ifndef __INTSTACK_H__
#define __INTSTACK_H__

#include <stdint.h>

typedef struct intstack {
	int value;
	intstack* next;
};



#endif /* __INTSTACK_H__ */
