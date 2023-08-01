
#include"queue.h"

void QueueInit(Queue * pq)
{
	pq->front = pq->QueueEntry;
	
	pq->rear = pq->QueueEntry - 1;
	
	pq->size = 0;
	
} 

void Enqueue(Queue * pq, QueueType data)
{	

	if(pq->rear == &(pq->QueueEntry[QueueMax-1]))
	{
		pq->rear = pq->QueueEntry;
	}
	else
	{
		pq->rear++;
	}
	
	*(pq->rear) = data;
	
	pq->size++;
	
}

QueueType Dequeue(Queue * pq)
{
	QueueType ReturnValue;
	
	ReturnValue = *(pq->front);
	
	if(pq->front == &(pq->QueueEntry[QueueMax-1]))
	{
		pq->front = pq->QueueEntry;
	}
	else
	{
		pq->front++;
	}
	
	pq->size--;
	
	return ReturnValue;
	
}

QueueStatus QueueEmpty(Queue * pq)
{
	if(pq->size == 0)
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
	if(pq->size == QueueMax)
	{
		return Queue_is_full;
	}
	else
	{
		return Queue_is_not_full;
	}
	
}

void QueueClear(Queue * pq)
{
	pq->front = pq->QueueEntry;
	
	pq->rear = pq->QueueEntry - 1;
	
	pq->size = 0;
}

void QueueTraverse(Queue * pq, void(*pf)(QueueType data))
{
	QueueType * i;
	uint32_t s;
	
	for(i = pq->front, s = 0; s < pq->size; s++, i++)
	{
		if(i == &(pq->QueueEntry[QueueMax-1]))
		{
			i = pq->QueueEntry;
		}
		
		
		(*pf)(*i);
		
	}
	
	
}