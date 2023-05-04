#include<stdio.h>

void main()
{
    int size;
    int i;
    double sum = 0;

    printf("Enter the number of data: ");
    scanf("%i", &size);

    float arr[size];

    for(i = 0; i < size; i++)
    {
        printf("%i. Enter number: ", i+1);
        scanf("%f", arr+i);
        sum+=arr[i];
    }

    printf("Average = %0.2lf", sum/size);

}