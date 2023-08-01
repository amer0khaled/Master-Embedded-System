
#include"StackAPIs.h"

void Stack_init(Stack * ps)
{	
	
	ps->base = ps->StackEntry;
	
	ps->top = ps->base;
		
}

/*
	precondition:  the stack is initialized and not full;
	postcondition: the data has been stored at the top of the stack;
*/

void Stack_push(StackType data, Stack * ps)
{	
	
	
	*(ps->top) = data;
		
	ps->top++;
		
}

/*
	precondition:  the stack is initialized and not empty;
	postcondition: the last element entered is returned first; 	
*/

StackType Stack_pop(Stack * ps)
{	

	ps->top--;
	
	return(*(ps->top));
	
}


uint8_t StackFull(Stack * ps)
{
	if(ps->top >= ps->base+MAX_STACK)
	{
		return Stack_is_full;
	}
	else
	{
		return Stack_is_not_full;
	}
}


uint8_t StackEmpty(Stack * ps)
{
	if(ps->top == ps->base)
	{
		return Stack_is_empty;
	}
	else
	{
		return Stack_is_not_empty;
	}
}

void StackClaer(Stack * ps)
{
	ps->top = ps->base;
}


uint32_t StackSize(Stack * ps)
{
	return ((ps->top) - (ps->base));
}

/*
	precondition: satck is initialized

*/

void StackTraverse(Stack *ps, void(*pf)(StackType data))
{	
	StackType *i = 0;
	for(i = ps->top; i > (ps->base); i--)
	{
		(*pf)(*i);
	}
}