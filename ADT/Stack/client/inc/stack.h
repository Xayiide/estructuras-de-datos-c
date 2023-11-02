#ifndef _STACK_H_
#define _STACK_H_

#define stack stack_t
typedef struct stack *stack; /* stack es un *stack_t                  */
                             /* en el cliente: stack_t es un *stack_t */

extern stack stack_new  (void);
extern int   stack_empty(stack s);
extern void  stack_push (stack s, void *e);
extern void *stack_pop  (stack s);
extern void  stack_free (stack *s);

#undef stack

#endif
