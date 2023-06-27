
/*count ones of binary*/

#include<stdio.h>

#define READ_BIT(num, bit) ((num & (1 << bit)) >> bit)

void count_ones(int num);

int main()
{
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);

    count_ones(num);

    return 0;
}

void count_ones(int num)
{   
    int i;
    int counter = 0;

    for(i = 0; i < 32; i++)
    {
        if(READ_BIT(num, i) == 1)
        {
            counter++;
        }
    }

    printf("number of ones= %d", counter);
}