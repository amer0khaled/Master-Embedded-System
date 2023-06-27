/*max ones between two zeros*/

#include "stdio.h"
char MAX_ONES(char num);

int main()
{
	int number;
	printf("Enter a number:");
	scanf("%d",&number);
	printf("Max number of ones are %d",MAX_ONES(number));
	return 0;
}
char MAX_ONES(char num)
{
	char count = 0;
	while(num!=0)
	{
		num = (num&(num<<1));
		count++;
	}
	return count;
}
