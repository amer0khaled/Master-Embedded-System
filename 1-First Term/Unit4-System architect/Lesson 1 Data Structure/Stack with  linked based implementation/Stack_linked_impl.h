#ifndef STACK_LINKED_IMPL_H_
#define STACK_LINKED_IMPL_H_

#include<stdint.h>


/*User Configuration*/
#define StackType uint32_t 



typedef enum 
{
	Stack_is_not_full,
	Stack_is_full,
	Stack_is_empty,
	Stack_is_not_empty,
	
}StackStatus;


typedef struct Stacknode
{
	StackType data;
	struct Stacknode * next;
	
}StackNode;


typedef struct Stack
{
	StackNode * top;
	uint32_t size;
	
}Stack;

/*APIs*/


void Stack_init(Stack * ps);

void Stack_push(StackType data, Stack * ps);

StackType Stack_pop(Stack * ps);

uint8_t StackFull(Stack * ps);

uint8_t StackEmpty(Stack * ps);

void StackClear(Stack * ps);

uint32_t StackSize(Stack * ps);

void StackTraverse(Stack *ps, void(*pf)(StackType data));







#endif/*STACK_LINKED_IMPL_H_*/