#ifndef QUEUE_LINKED_H_
#define QUEUE_LINKED_H_

#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define QueueType uint32_t


#define DPRINTF(...)     {fflush(stdin);\
						  fflush(stdout);\
						  printf(__VA_ARGS__);\
						  fflush(stdin);\
						  fflush(stdout);}
						  
						  


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
	uint8_t first_name[20];
	uint8_t last_name[20];
	uint32_t ID;
	float GPA;
	uint32_t courses[5];
	struct queuenode * next;
}QueueNode;


typedef struct queue
{
	QueueNode * front;
	QueueNode * rear;
	uint32_t size;
}Queue;


void QueueInit(Queue * pq);

QueueStatus ADD_Student_Manually(Queue * pq);

void Search_By_ID(Queue * pq);

void Search_By_FirstName(Queue * pq);

void Search_By_CourseID(Queue * pq);

void Total_Students_Number(Queue * pq);

void Delete_By_ID(Queue * pq);

void Update_By_ID(Queue * pq);

void Show_All_Students(Queue * pq);

QueueStatus QueueEmpty(Queue * pq);

QueueStatus QueueFull(Queue * pq);

void QueueClear(Queue * pq);




#endif /*QUEUE_LINKED_H_*/