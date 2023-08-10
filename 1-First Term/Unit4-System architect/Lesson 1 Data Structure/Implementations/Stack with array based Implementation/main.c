
#include<stdio.h>
#include"StackAPIs.h"

int main()
{
	Stack s;
	StackType temp, i;
	
	Stack_init(&s);
	
	for(i = 0; i < 12; i++)
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
	
	printf("\nStack Size = %d\n", StackSize(&s));
	
	for(i = 0; i < 23; i++)
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
	
	printf("\nStack Size = %d\n", StackSize(&s));
	
	
	return 0;
}