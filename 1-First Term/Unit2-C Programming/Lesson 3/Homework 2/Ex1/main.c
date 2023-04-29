#include<stdio.h>

#define READ_BIT(NUM, BIT) NUM&(1<<BIT)

int main()
{
    int num;

    printf("Enter an integer you want to check: ");
    scanf("%i", &num);

    if(READ_BIT(num, 0) == 1)
    {
        printf("%i is odd.", num);
    }
    else
    {
        printf("%i is even.", num);
    }


    return 0;
}