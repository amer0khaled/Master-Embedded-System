#include<stdio.h>
#include<string.h>

void main()
{
    char arr[50];
    int counter = 0;
    int i = 0;

    printf("Enter a string: ");

    gets(arr);

    while(arr[i] != '\0')
    {
        counter++;
        i++;
    }

    printf("Length of string: %i", counter);

}
