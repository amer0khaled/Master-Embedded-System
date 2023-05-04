#include<stdio.h>
#include<string.h>

void main()
{
    char arr[50];
    char search_char;
    int i;
    int counter = 0;

    printf("\nEnter a string: ");
    gets(arr);

    printf("\nEnter a character to find frequency: ");
    scanf("%c", &search_char);

    for (i = 0; i < strlen(arr); i++)
    {
        if(search_char == arr[i])
        {
            counter++;
        }
    }

    printf("Frequency of %c = %i", search_char, counter);
    
}