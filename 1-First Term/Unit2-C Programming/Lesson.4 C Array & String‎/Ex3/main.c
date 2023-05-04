#include<stdio.h>

void main()
{
    int rows;
    int columns;
    int i;
    int j;

    printf("Enter rows and columns of matrix:\n");

    scanf("%i%i", &rows, &columns);

    int arr[rows][columns];

    int transpose[columns][rows];

    printf("Enter element of matrix:\n");

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            printf("Enter element a%i%i: ", i+1, j+1);
            scanf("%d", arr[i]+j);

        }
    }

    printf("Entered Matrix:\n");

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            printf("%d", arr[i][j]);
            printf("\t");
        }

        printf("\n");
    }

    printf("Transpose of matrix:\n");

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            transpose[j][i] = arr[i][j];
        }
    }

    for(i = 0; i < columns; i++)
    {
        for(j = 0; j < rows; j++)
        {
            printf("%d", transpose[i][j]);
            printf("\t");
        }

        printf("\n");
    }


}
