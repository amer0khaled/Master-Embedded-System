

#ifndef _STACKAPIS_H
#define _STACKAPIS_H

#include<stdint.h>


/*User Configuration*/

#define StackType uint32_t 

#define MAX_STACK 5


typedef enum 
{
	Stack_is_not_full,
	Stack_is_full,
	Stack_is_empty,
	Stack_is_not_empty,
	Stack_Error
	
}StackStatus;



typedef struct stack
{	
	StackType * base;
	StackType * top;
	StackType StackEntry[MAX_STACK];
	
} Stack;


void Stack_init(Stack * ps);

void Stack_push(StackType data, Stack * ps);

StackType Stack_pop(Stack * ps);

uint8_t StackFull(Stack * ps);

uint8_t StackEmpty(Stack * ps);

void StackClaer(Stack * ps);

uint32_t StackSize(Stack * ps);

void StackTraverse(Stack *ps, void(*pf)(StackType data));

#endif/*_STACKAPIS_H*/