#include<stdio.h>

void main()
{
    int size;
    int search_num;
    int i;
    int flag = 0;

    printf("Enter number of elements: ");
    scanf("%i", &size);

    int arr[size];

    for(i = 0; i < size; i++)
    {
        scanf("%i", arr+i);
    }

    printf("Enter the element to be searched: ");
    scanf("%i", &search_num);


    for(i = 0; i < size; i++)
    {
        if(search_num == arr[i])
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        printf("Number found at location = %i", i+1);
    }
    else
    {
        printf("Not found");
    }


}