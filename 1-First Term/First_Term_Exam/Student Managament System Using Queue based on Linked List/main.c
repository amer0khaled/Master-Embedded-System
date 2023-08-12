#include"queue_linked.h"

int main()
{	
	uint32_t choice;
	uint32_t loop = 1;
	Queue q;
	
	QueueInit(&q);
	
	DPRINTF("Welcome to Student Management System\n\n");
	
	
		
	
	while(loop)
	{
		
		DPRINTF("Choose The Task That You Want to Perform\n");
		
		DPRINTF("1. Add The Student Details Manually\n");
		//DPRINTF("2. Add The Student Details From Text File\n");
		DPRINTF("3. Find The Student Details by ID\n");
		DPRINTF("4. Find The Student by First Name\n");
		DPRINTF("5. Find The Student by Course ID\n");
		DPRINTF("6. Find The Total Number Of Student\n");
		DPRINTF("7. Delete The Student Details by ID\n");
		DPRINTF("8. Update The Student Details by ID\n");
		DPRINTF("9. Show All Students Information\n");
		DPRINTF("10. To Exit\n");
			
		DPRINTF("Enter Your Choice To Perform The Task: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				ADD_Student_Manually(&q);
				break;
				
			case 3:
				Search_By_ID(&q);
				break;
				
			case 4:
				Search_By_FirstName(&q);
				break;
				
			case 5:
				Search_By_CourseID(&q);
				break;
				
			case 6:
				Total_Students_Number(&q);
				break;
				
			case 7:
				Delete_By_ID(&q);
				break;
				
			case 8:
				Update_By_ID(&q);
				break;
				
			case 9:
				Show_All_Students(&q);
				break;
				
			case 10:
				loop = 0;
				break;
			
				
		}
		
			
	}
	
	
	
	
	
	
	return 0;
}