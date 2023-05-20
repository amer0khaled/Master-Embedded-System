#include<stdio.h>
#include<stdlib.h>

void main()
{
    int size;
    int i, j;

    printf("Enter The Size Of Array: ");
    scanf("%i", &size);

    int * ptr1 = (int *)malloc(size * sizeof(int));

    int * ptr2 = (int *)malloc(size * sizeof(int));

    printf("Enter The Elements Of The Array: ");

    for(i = 0, j = size -1; i < size; i++, j--)
    {
        scanf("%i", ptr1+i);
        ptr2[j] = ptr1[i];
    }

    printf("Array After Reversing: ");

    for(i = 0; i < size; i++)
    {
        printf("%i ", ptr2[i]);
    }
}