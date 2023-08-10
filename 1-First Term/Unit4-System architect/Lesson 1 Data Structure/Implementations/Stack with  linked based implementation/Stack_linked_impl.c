#include<stdlib.h>
#include"Stack_linked_impl.h"

void Stack_init(Stack * ps)
{
	ps->top = NULL;
	ps->size = 0;
}

StackStatus Stack_push(StackType data, Stack * ps)
{
	StackNode * pn = (StackNode *) malloc(sizeof(StackNode));
	
	if(pn != NULL)
	{
		pn->data = data;
		
		pn->next = ps->top;
		
		ps->top = pn;
	
		ps->size++;
		
		return Stack_NO_Error;
	}
	else
	{
		return Stack_Error;
	}
	
	
}

StackType Stack_pop(Stack * ps)
{	
	StackType ReturnValue;
	StackNode * temp = NULL;
	
	ReturnValue = ps->top->data;
	
	temp = ps->top->next;
	
	free(ps->top);
	
	ps->top = temp;
	
	ps->size--;
	
	return ReturnValue;
	
}

uint8_t StackEmpty(Stack * ps)
{
	if(ps->top == NULL)
	{
		return Stack_is_empty;
	}
	else
	{
		return Stack_is_not_empty;
	}
	
}


uint8_t StackFull(Stack * ps)
{
	return Stack_is_not_full;
}

void StackClear(Stack * ps)
{
	StackNode * pn = ps->top;
	
	while(pn != NULL)
	{
		pn = pn->next;
		free(ps->top);
		ps->top = pn;
	}
	
	ps->size = 0;

} 

void StackTraverse(Stack *ps, void(*pf)(StackType data))
{
	StackNode * pn = ps->top;
	
	while(pn != NULL)
	{
		(*pf)(pn->data);
		pn = pn->next;
	}
	
}

uint32_t StackSize(Stack * ps)
{
	return ps->size;
}