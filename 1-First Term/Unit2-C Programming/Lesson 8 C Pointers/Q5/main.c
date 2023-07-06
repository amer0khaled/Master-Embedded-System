
/*array of pointers to struct and pointer to array of pointers to struct*/

#include<stdio.h>

struct SEmployee
{
	char name[20];
	int id;
};

int main(int argc, char const *argv[])
{	
	struct SEmployee emp1 = {"amer", 1000}, emp2 = {"mohamed", 1001}, emp3 = {"ALEX", 1002};

	struct SEmployee (* arr[3]) = {&emp1 , &emp2 , &emp3};

	struct SEmployee (*(*ptr)[3]) = (struct SEmployee *((*)[3]))arr;


	printf("Employee Name is: %s\n", (**((*ptr)+2)).name);

	printf("Employee ID is: %d\n", (**((*ptr)+2)).id);
	
	return 0;
}