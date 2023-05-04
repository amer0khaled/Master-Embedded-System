#include<stdio.h>

int main()
{   
    signed int num;
    int i;
    unsigned long long factorial = 1;

    printf("Enter an integer: ");
    scanf("%i", &num);

    if(num < 0)
    {
        printf("Error!!! Factorial of negative number doesn't exist");
    }

    for(i = num; i > 0; i--)
    {
        factorial*=i; 
    }

    printf("Factorial = %llu", factorial);

    return 0;
}