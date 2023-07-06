
/*printing all alphabets*/

#include<stdio.h>

void main()
{	

	int i;
	char *ptr;

	ptr = (char *) 'A';

	for(i = 0; i < 26; i++)
	{
		printf("%c ", ptr+i);
	}
}