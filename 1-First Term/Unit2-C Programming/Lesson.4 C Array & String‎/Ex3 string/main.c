#include<stdio.h>
#include<string.h>

void main()
{
    char arr[50];
    char rev_arr[50];
    int i;

    printf("\nEnter the string: ");
    gets(arr);

    for(i = 0; i < strlen(arr); i++)
    {
        rev_arr[i] = arr[strlen(arr)-1-i];
    }

    rev_arr[i] = '\0';

    printf("\n%s\n\n", rev_arr);

}