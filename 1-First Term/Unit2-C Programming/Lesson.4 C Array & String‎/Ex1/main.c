#include<stdio.h>

void main()
{
    float matrix1[2][2];
    float matrix2[2][2];
    int i;
    int j;
    double sum[2][2];

    printf("Enter the element of 1st matrix:\n");

    for(i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter a%i%i: ",i+1, j+1);

            scanf("%f", matrix1[i]+j);

        }
        
    }

    printf("Enter the element of 2nd matrix:\n");

    for(i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter b%i%i: ",i+1, j+1);

            scanf("%f", matrix2[i]+j);

        }
        
    }

    for(i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
           sum[i][j] = matrix1[i][j] + matrix2[i][j];

           printf("%0.1lf\t", sum[i][j]);
        }
        
        printf("\n");
    }

 
}
