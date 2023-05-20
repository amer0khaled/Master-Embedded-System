#include<stdio.h>

#define READ_4Least_BIT(num) ((num&(1U<<7))>>7)

void main()
{
    int num;
    printf("Enter number: ");
    scanf("%i", &num);

    printf("4th Least Bit is: %i", READ_4Least_BIT(num));
}