
/*print reverse of string*/

#include<stdio.h>
#include<string.h>

void main()
{
	char str[50];
	int i;
	char *ptr = str;


	printf("Enter the string: ");
	gets(str);

	printf("The reversed string is: ");

	for(i = strlen(str); i >= 0; i--)
	{
		printf("%c", ptr[i]);
	}



}