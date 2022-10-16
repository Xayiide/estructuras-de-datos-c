#ifndef __DOBLEENLAZ_H__
#define __DOBLEENLAZ_H__

#include <stdint.h> /* uint8_t */


struct dlNode {
	void *value;
	struct dlNode* next;
	struct dlNode* prev;
};

struct dlList {
	struct dlNode* ppo;
	uint8_t numitems;
};


struct dlList* dlLinit();
void     dlLinsert (struct dlList* list, void *v);
int8_t   dlLisempty(struct dlList* list);
void    *dlLpeek   (struct dlList* list, int8_t pos);
uint8_t  dlLnumelem(struct dlList* list);

#endif /* __DOBLEENLAZ_H__ */

