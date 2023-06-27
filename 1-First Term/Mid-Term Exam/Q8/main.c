/*reverse elments of array*/

#include<stdio.h>
#include<stdlib.h>

void reverse_arr(int *ptr, int size);
int main()
{
    int size,i;
    printf("enter size of array: ");
    scanf("%d", &size);

    int * ptr = (int *) malloc(size * sizeof(int));

    printf("Enter the elements of array: ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", ptr+i);
    }

    reverse_arr(ptr, size);


    printf("The array After reversing: ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }

    return 0;
}

void reverse_arr(int *ptr, int size)
{
    int i;
    int temp;
    for(i = 0; i < size/2; i++)
    {
        temp = ptr[i];
        ptr[i] = ptr[size-1-i];
        ptr[size-1-i] = temp;
    }
}
