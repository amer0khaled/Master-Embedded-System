#include<stdio.h>
#include<stdlib.h>

int detect_unique(int * ptr, int size);
void sorting_array(int *ptr, int size);

int main()
{
    int i;
    int size;
    int index;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    int * arr = (int *) malloc(size * sizeof(int));

    printf("Enter the elements of the array: ");

    for(i = 0; i < size; i++)
    {
        scanf("%d", arr+i);
    }

    sorting_array(arr, size);

    index = detect_unique(arr, size);

    printf("The Unique Nubmer is: %d", arr[index]);

    return 0;
}

void sorting_array(int *ptr, int size)
{
    int i,j;

    for(i= 0; i < size-1; i++)
    {
        for(j = 0; j < size-i-1; j++)
        {
            if(ptr[j] > ptr[j+1])
            {
                ptr[j] = ptr[j] ^ ptr[j+1];
                ptr[j+1] = ptr[j] ^ ptr[j+1];
                ptr[j] = ptr[j+1] ^ ptr[j];
            }
        }
    }

}

int detect_unique(int * ptr, int size)
{
    int i = 0, j = 0;

    for (i = 0; i < size-1; i++)
    {

        for(j = i+1; j < size; j++)
        {
            if(ptr[i] == ptr[j])
            {
                break;
            }
        }

        if(j == size)
        {
            break;
        }
    }

    return i;

}
