#ifndef QUEUE_LINKED_H_
#define QUEUE_LINKED_H_

#include<stdint.h>
#include<stdlib.h>

/*user configuration*/

#define QueueType uint32_t


typedef enum
{
	Queue_is_empty,
	Queue_is_not_empty,
	Queue_is_full,
	Queue_is_not_full,
	Queue_NO_Error,
	Queue_Error
	
}QueueStatus;


typedef struct queuenode
{
	QueueType data;
	struct queuenode * next;
}QueueNode;


typedef struct queue
{
	QueueNode * front;
	QueueNode * rear;
	uint32_t size;
}Queue;


void QueueInit(Queue * pq);

QueueStatus Enqueue(Queue * pq, QueueType data);

QueueType Dequeue(Queue * pq);

QueueStatus QueueEmpty(Queue * pq);

QueueStatus QueueFull(Queue * pq);

void QueueClear(Queue * pq);

void QueueTraverse(Queue * pq, void(*pf)(QueueType data));


#endif /*QUEUE_LINKED_H_*/