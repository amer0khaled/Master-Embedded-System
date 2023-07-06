
/*print array elements in reverse order*/

#include<stdio.h>


int main(int argc, char const *argv[])
{
	int arr[5];

	int i;
	int * ptr = arr;

	printf("Enter the elements of array:\n");

	for(i = 0; i < 5; i++)
	{
		scanf("%d", ptr+i);
	}


	printf("The reeversed array is:\n");

	for(i = 4; i >= 0; i--)
	{
		printf("%d ", ptr[i]);
	}

	return 0;
}
