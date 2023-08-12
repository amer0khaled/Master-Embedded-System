#include"queue_linked.h"



void QueueInit(Queue * pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->size = 0;
}


QueueStatus ADD_Student_Manually(Queue * pq)
{	
	QueueNode * pn = (QueueNode *)malloc(sizeof(QueueNode));
	
	if(pn != NULL)
	{	
		uint32_t i;
		
		//Add student details

		DPRINTF("\nEnter the First Name: ");
		scanf("%s", pn->first_name);
		DPRINTF("\n");
		
		DPRINTF("Enter the Last Name: ");
		scanf("%s", pn->last_name);
		DPRINTF("\n");
		
		DPRINTF("Enter the ID: ");
		scanf("%d", &(pn->ID));
		DPRINTF("\n");
		
		DPRINTF("Enter the Student GPA: ");
		scanf("%f", &(pn->GPA));
		DPRINTF("\n");
		
		DPRINTF("Enter the Courses ID: ");
		for(i = 0; i < 5; i++)
		{
			scanf("%d", pn->courses+i);
		}
		DPRINTF("\n");
		
		pn->next = NULL;
		
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



void Search_By_ID(Queue * pq)
{
	if(QueueEmpty(pq) == Queue_is_empty)
	{
		DPRINTF("\n\n[Error] Queue is Empty!!\n");
		DPRINTF("-----------------------------\n");
	}
	else
	{	
		uint32_t search_id;
		
		DPRINTF("Enter the ID: ");
		scanf("%d", &search_id);
		
		QueueNode * pn = NULL;
		uint32_t iterator = 0;
		
		for(pn = pq->front; pn != NULL; pn = pn->next)
		{
			if(pn->ID == search_id)
			{
				DPRINTF("\nStudent First Name: %s\n", pn->first_name);
				DPRINTF("Student Last Name: %s\n", pn->last_name);
				DPRINTF("Student ID: %d\n", pn->ID);
				DPRINTF("Student GPA: %f\n", pn->GPA);
				
				for(iterator = 0; iterator < 5; iterator++)
				{
					DPRINTF("Course No. %d ID: %d\n", iterator+1, pn->courses[iterator]);
				}
				DPRINTF("-----------------------------\n");
				break;
				
			}
			
		}
		
		if(iterator == 0)
		{
			DPRINTF("\n\n[Error] ID %d Not Found!!\n", search_id);
			DPRINTF("-----------------------------\n");
		}
	}
	
}

void Search_By_FirstName(Queue * pq)
{
	if(QueueEmpty(pq) == Queue_is_empty)
	{
		DPRINTF("\n\n[Error] Queue is Empty!!\n");
		DPRINTF("-----------------------------\n");
	}
	else
	{	
		uint8_t search_first_name[20];
		
		DPRINTF("Enter The First Name: ");
		scanf("%s", search_first_name);
		
		QueueNode * pn = NULL;
		uint32_t iterator = 0;
		
		for(pn = pq->front; pn != NULL; pn = pn->next)
		{
			if(strcmp(pn->first_name, search_first_name) == 0)
			{
				DPRINTF("\nStudent First Name: %s\n", pn->first_name);
				DPRINTF("Student Last Name: %s\n", pn->last_name);
				DPRINTF("Student ID: %d\n", pn->ID);
				DPRINTF("Student GPA: %f\n", pn->GPA);
				
				for(iterator = 0; iterator < 5; iterator++)
				{
					DPRINTF("Course No. %d ID: %d\n", iterator+1, pn->courses[iterator]);
			
				}
				DPRINTF("-----------------------------\n");
				break;
				
			}
			
		}
		
		if(iterator == 0)
		{
			DPRINTF("\n\n[Error] First Name %s Not Found!!\n", search_first_name);
			DPRINTF("-----------------------------\n");
		}
	}
	
}

void Search_By_CourseID(Queue * pq)
{
	if(QueueEmpty(pq) == Queue_is_empty)
	{
		DPRINTF("\n\n[Error] Queue is Empty!!\n");
		DPRINTF("-----------------------------\n");
	}
	else
	{
		uint32_t course_id;
		
		DPRINTF("Enter Course ID: ");
		scanf("%d", &course_id);
		
		QueueNode * pn = NULL;
		uint32_t iterator = 0;
		uint32_t course_iter = 0;
		uint32_t found = 0;
		
		for(pn = pq->front; pn != NULL; pn = pn->next)
		{	
			for(course_iter = 0; course_iter < 5; course_iter++)
			{
				if(pn->courses[course_iter] == course_id)
				{	
					found = 1;
					DPRINTF("\nStudent First Name: %s\n", pn->first_name);
					DPRINTF("Student Last Name: %s\n", pn->last_name);
					DPRINTF("Student ID: %d\n", pn->ID);
					DPRINTF("Student GPA: %f\n", pn->GPA);
				
				for(iterator = 0; iterator < 5; iterator++)
				{
					DPRINTF("Course No. %d ID: %d\n", iterator+1, pn->courses[iterator]);
				}
				DPRINTF("-----------------------------\n");
					break;
				
				}
			}
			
			
		}
		
		if(found == 0)
		{
			DPRINTF("\n\n[Error] Course ID %d Not Found!!\n", course_id);
			DPRINTF("-----------------------------\n");
		}
	}
}

void Total_Students_Number(Queue * pq)
{
	DPRINTF("\n[INFO] Total Number Of Students: %d\n", pq->size);
	DPRINTF("-----------------------------\n");
}


void Delete_By_ID(Queue * pq)
{
	if(QueueEmpty(pq) == Queue_is_empty)
	{
		DPRINTF("\n\n[Error] Queue is Empty!!\n");
		DPRINTF("-----------------------------\n");
	}
	else
	{
		uint32_t delete_id;
		
		DPRINTF("Enter The ID: ");
		scanf("%d", &delete_id);
		printf("\n");
		
		QueueNode * pn = NULL;
		QueueNode * temp1 = NULL;
		QueueNode * temp2 = NULL;
		uint32_t found = 0;
	
		for(pn = pq->front; pn != NULL; pn = pn->next)
		{	
	
			if(pn->ID == delete_id)
			{	
				found = 1;
				
				
				if(pn == pq->front)   //if the selected node is the first one
				{
					pq->front = pq->front->next;
				}
				else if(pn->next == NULL)  //if the selected node is the last one
				{	
					temp1 = pq->front;

					while(temp1->next != NULL)
					{
						temp1 = temp1->next;
						
						if(temp1->next != NULL)
						{
							temp2 = temp1;
						}
						
					}

					pq->rear = temp2;
					temp2->next = NULL;
				}
				else //if the selected node in the middle
				{
					pq->front->next = pn->next;
				}
		
				free(pn);
				
				pq->size--;
				
				break;
			}
		}
		
		if(found == 0)
		{
			DPRINTF("\n\n[Error] ID %d Not Found!!\n", delete_id);
			DPRINTF("-----------------------------\n");
		}
		
	}
	
	
}


void Update_By_ID(Queue * pq)
{	
	if(QueueEmpty(pq) == Queue_is_empty)
	{
		DPRINTF("\n\n[Error] Queue is Empty!!\n");
		DPRINTF("-----------------------------\n");
	}
	else
	{
		uint32_t modified_id;
		
		DPRINTF("Enter The ID: ");
		scanf("%d", &modified_id);
		
		
		
		QueueNode * pn = NULL;
		uint32_t found = 0;
	
		for(pn = pq->front; pn != NULL; pn = pn->next)
		{
			if(pn->ID == modified_id)
			{	
				uint32_t i;
				found = 1;
				
				//update student details

				DPRINTF("\nEnter the First Name: ");
				scanf("%s", pn->first_name);
				DPRINTF("\n");
				
				DPRINTF("Enter the Last Name: ");
				scanf("%s", pn->last_name);
				DPRINTF("\n");
				
				DPRINTF("Enter the ID: ");
				scanf("%d", &(pn->ID));
				DPRINTF("\n");
				
				DPRINTF("Enter the Student GPA: ");
				scanf("%f", &(pn->GPA));
				DPRINTF("\n");
				
				DPRINTF("Enter the Courses ID: ");
				for(i = 0; i < 5; i++)
				{
					scanf("%d", pn->courses+i);
				}
				DPRINTF("\n");
				break;
			}
		
		}
		
		if(found == 0)
		{
			DPRINTF("\n\n[Error] ID %d Not Found!!\n", modified_id);
			DPRINTF("-----------------------------\n");
		}
	}
	
}


void Show_All_Students(Queue * pq)
{
	if(QueueEmpty(pq) == Queue_is_empty)
	{
		DPRINTF("\n\n[Error] Queue is Empty!!\n");
		DPRINTF("-----------------------------\n");
	}
	else
	{
		QueueNode * pn = NULL;
		uint32_t iterator;
		
		for(pn = pq->front; pn != NULL; pn = pn->next)
		{
			DPRINTF("\nStudent First Name: %s\n", pn->first_name);
			DPRINTF("Student Last Name: %s\n", pn->last_name);
			DPRINTF("Student ID: %d\n", pn->ID);
			DPRINTF("Student GPA: %f\n", pn->GPA);
				
			for(iterator = 0; iterator < 5; iterator++)
			{
				DPRINTF("Course No. %d ID: %d\n", iterator+1, pn->courses[iterator]);
			}
			
			DPRINTF("-----------------------------\n");
		}
		
	}
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
