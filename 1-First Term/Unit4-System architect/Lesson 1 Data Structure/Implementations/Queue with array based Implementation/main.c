
#include<stdio.h>
#include"queue.h"

int main()
{
	Queue q;
	QueueType temp;
	
	QueueInit(&q);
	
	int i = 0;
	
	for(i = 0; i < 12; i++)
	{
		if(QueueFull(&q) == Queue_is_not_full)
		{
			Enqueue(&q, i);
			printf("\nEntered Value = %d\n", i);
		}
		else
		{
			printf("\nQueue is Full\n");
			break;
		}
	}
	
	for(i = 0; i < 12; i++)
	{
		if(QueueEmpty(&q) == Queue_is_not_empty)
		{
			temp = Dequeue(&q);
			printf("\nServed Value = %d\n", temp);
		}
		else
		{
			printf("\nQueue is Empty\n");
			break;
		}
	}
	
	
	
	
	return 0;
}