#include<stdio.h>
#include<stdlib.h>

void main()
{   
    int size1;
    int size2;
    int i;
    int temp_size;

    printf("Enter the Size of Array no. 1: ");
    scanf("%i", &size1);

    printf("Enter the Size of Array no. 2: ");
    scanf("%i", &size2);

    int * ptr1 = (int *)malloc(size1 * sizeof(int));

    int * ptr2 = (int *)malloc(size2 * sizeof(int));

    temp_size = size1 > size2 ? size1 : size2;

    int * temp = (int *)malloc(temp_size * sizeof(int));


    printf("Enter Elements of Array 1 >- ");
    for (i = 0; i < size1; i++)
    {
        scanf("%i", ptr1+i);
    }

    printf("Enter Elements of Array 2 >- ");
    for (i = 0; i < size2; i++)
    {
        scanf("%i", ptr2+i);
    }

    if(size1 > size2)
    {
        int * new_ptr2 = (int *)realloc(ptr2, size1);

        if(new_ptr2 != 0)
        {
            ptr2 = new_ptr2;
        }

    }
    else
    {
        int * new_ptr1 = (int *)realloc(ptr1, size2);

        if(new_ptr1 != 0)
        {
            ptr1 = new_ptr1;
        }

    }

    for (i = 0; i < (size1 > size2 ? size1 : size2); i++)
    {
        temp[i] = ptr1[i];
        ptr1[i] = ptr2[i];
        ptr2[i] = temp[i];
    }

    printf("Array 2 After Swapping: ");
    for(i = 0; i < size1; i++)
    {
        printf("%i ", ptr2[i]);
    }

    printf("\nArray 1 After Swapping: ");
    for(i = 0; i < size2; i++)
    {
        printf("%i ", ptr1[i]);
    }
    
}