
#include<stdio.h>
#include"Stack_linked_impl.h"

int main()
{
	Stack s;
	StackType temp, i;
	
	Stack_init(&s);
	
	for(i = 0; i < 8; i++)
	{
		if(StackFull(&s) != Stack_is_full)
		{
			Stack_push(i, &s);
			printf("data pushed: %d\n", i);
		}
		else
		{	
			printf("\nstack is full\n");
			break;
		}
	}
	
	for(i = 0; i < 15; i++)
	{
		if(StackEmpty(&s) != Stack_is_empty)
		{
			temp = Stack_pop(&s);
			printf("data poped: %d\n", temp);
		}
		else
		{	
			printf("\nstack is empty\n");
			break;
		}
		
	}
	
	
	return 0;
}