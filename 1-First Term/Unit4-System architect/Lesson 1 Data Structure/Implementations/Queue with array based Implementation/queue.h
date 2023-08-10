
#ifndef QUEUE_H
#define QUEUE_H

#include<stdint.h>

/*user configuration*/

#define QueueType uint32_t
#define QueueMax 5



typedef enum
{
	Queue_is_empty,
	Queue_is_not_empty,
	Queue_is_full,
	Queue_is_not_full
	
}QueueStatus;



typedef struct
{
	QueueType * front;
	QueueType * rear;
	QueueType size;
	QueueType QueueEntry[QueueMax]
	
}Queue;


void QueueInit(Queue * pq);

void Enqueue(Queue * pq, QueueType data);

QueueType Dequeue(Queue * pq);

QueueStatus QueueEmpty(Queue * pq);

QueueStatus QueueFull(Queue * pq);

void QueueClear(Queue * pq);

void QueueTraverse(Queue * pq, void(*pf)(QueueType data));



#endif/*QUEUE_H*/