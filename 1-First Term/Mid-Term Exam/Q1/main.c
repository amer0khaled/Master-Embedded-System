


/*sum digits of a number*/
#include<stdio.h>

unsigned int calc_number_of_digits(unsigned int num);

unsigned int sum_digits(unsigned int num, unsigned int number_of_digits);

int main(void)
{
    unsigned int num;
    unsigned int result = 0;
    unsigned int number_of_digits = 0;

    printf("Enter the number: ");
    scanf("%u", &num);

    number_of_digits = calc_number_of_digits(num);

    result = sum_digits(num, number_of_digits);

    printf("result = %u", result);

    return 0;

}


/*to calculate number of digits*/
unsigned int calc_number_of_digits(unsigned int num)
{
    int counter = 1;

    while(num = num / 10)
    {
        counter++;
    }

    return counter;
}


/*to sum digits*/
unsigned int sum_digits(unsigned int num, unsigned int number_of_digits)
{   
    unsigned int i= 0;
    unsigned int temp = 0;
    unsigned int sum = 0;

    for(i = 0; i < number_of_digits; i++)
    {
        temp = num % 10;
        num = num / 10;
        sum+=temp;
    }

    return sum;

}
