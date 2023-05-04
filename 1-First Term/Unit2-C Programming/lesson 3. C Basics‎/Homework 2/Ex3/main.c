#include<stdio.h>

int main()
{
    float num1;
    float num2;
    float num3;

    printf("Enter three numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    if(num1 > num2)
    {
        if(num1 > num3)
        {
            printf("Largest number = %f", num1);
        }
    }
    else
    {
        if(num2 > num3)
        {
            printf("Largest number = %f", num2);
        }
        else
        {
            printf("Largest number = %f", num3);
        }
    }

    return 0;
}