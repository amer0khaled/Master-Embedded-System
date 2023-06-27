


/*sum digits of a number*/

#include <stdio.h>
int sum_digits(int num);
int main()
{
    int num;

    printf("Enter num: ");
    scanf("%d", &num);

    printf("sum of digits = %d", sum_digits(num));
    
    return 0;
}

int sum_digits(int num)
{   
    int sum = 0;
    int temp = 1;

    while (temp != 0)
    {
        temp = num %10;
        num = num /10;
        sum+=temp;
    }

    return sum;
}