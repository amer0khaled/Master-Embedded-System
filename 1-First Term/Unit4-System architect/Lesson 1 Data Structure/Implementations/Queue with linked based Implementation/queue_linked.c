#include"queue_linked.h"



void QueueInit(Queue * pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->size = 0;
}

QueueStatus Enqueue(Queue * pq, QueueType data)
{	
	QueueNode * pn = (QueueNode *)malloc(sizeof(QueueNode));
	
	if(pn != NULL)
	{
		pn->next = NULL;
		pn->data = data;
		
		//special case when the queue is empty
		if(pq->rear == NULL)
		{
			pq->rear = pn;
			pq->front = pn;
		}
		else
		{
			pq->rear->next = pn;
			pq->rear = pn;
		}
		
			
		pq->size++;
		
		return Queue_NO_Error;
	}
	else
	{
		return Queue_Error;
	}
	
}

QueueType Dequeue(Queue * pq)
{	
	QueueType ReturnValue;
	
	QueueNode * pn = pq->front;
	ReturnValue = pn->data;
	
	pq->front = pq->front->next;
	
	free(pn);
	
	//special case when the queue has one node to be served
	if(pq->front == NULL)
	{
		pq->rear = NULL;
	}
	
	pq->size--;
	
	return ReturnValue;
}

QueueStatus QueueEmpty(Queue * pq)
{
	if((pq->front == NULL)&&(pq->rear == NULL))
	{
		return Queue_is_empty;
	}
	else
	{
		return Queue_is_not_empty;
	}
}

QueueStatus QueueFull(Queue * pq)
{
	return Queue_is_not_full;
}

void QueueClear(Queue * pq)
{	
	/*
		moving with two pointers
	*/
	while(pq->front != NULL)
	{
		pq->rear = pq->front->next;
		free(pq->front);
		pq->front = pq->rear;
	}
	
	pq->size = 0;
}

void QueueTraverse(Queue * pq, void(*pf)(QueueType data))
{
	QueueNode * pn = NULL;
	
	for(pn = pq->front; pn != NULL; pn = pn->next)
	{
		(*pf)(pn->data);
	}
	
}
