#include<stdio.h>

int main()
{
    int num;
    int i;
    long long sum = 0;

    printf("Enter an integer: ");

    scanf("%i", &num);

    for ( i = 0; i <= num; i++)
    {
        sum+=i;
    }

    printf("Sum = %lld", sum);
    


    return 0;
}