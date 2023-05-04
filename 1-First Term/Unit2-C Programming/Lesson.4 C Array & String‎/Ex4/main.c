#include<stdio.h>

void main()
{
    int size;
    int ins_num;
    int loc;
    int temp;
    int i;

    printf("Enter no. of elements: ");

    scanf("%i", &size);

    int arr[size];
    int new_arr[size+1];

    for(i = 0; i < size; i++)
    {
        scanf("%i", arr+i);
    }

    printf("Enter the no. to be inserted: ");
    scanf("%i", &ins_num);

    printf("Enter the location: ");
    scanf("%i", &loc);

    for(i = 0; i < size+1; i++)
    {
        if(i < loc-1)
        {
            new_arr[i] = arr[i];
        }
        else if(i >= loc-1)
        {
            new_arr[i+1] = arr[i];
        }

    }

    new_arr[loc-1] = ins_num;


    printf("the array after inseting a number:\n");

    for (i = 0; i < size+1; i++)
    {
        printf("%i ", new_arr[i]);
    }
    

}