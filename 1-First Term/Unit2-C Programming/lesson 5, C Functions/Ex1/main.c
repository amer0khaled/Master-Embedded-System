#include<stdio.h>

void Get_prime(int num1, int num2);

int main()
{
    int num1;
    int num2;

    printf("Enter two numbers (intervals):\n");

    scanf("%i%i", &num1, &num2);

    printf("prime numbers between %i and %i are: ", num1, num2);

    Get_prime(num1, num2);

    return 0;

}

void Get_prime(int num1, int num2)
{
    int iterator1;
    int iterator2;
    int flag = 0;

    if((num1 != 0 || num1 != 1) && (num2 != 0 || num2 != 1))
    {
        for(iterator1 = num1; iterator1 <= num2; iterator1++)
        {
            for (iterator2 = 2; iterator2 <= iterator1/2; iterator2++)
            {
                if(iterator1 % iterator2 == 0)
                {
                    flag = 1;
                    break;
                }
            }

            if(iterator2 == ((iterator1/2) + 1))
            {
                printf("%i ", iterator1);
            }

        }

    }

}

