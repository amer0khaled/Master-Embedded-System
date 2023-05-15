#include<stdio.h>


unsigned long long recursion(int num)
{
	unsigned long long result;
    if (num > 0)
    {
        result = (num * recursion(num-1));
    }
    else
    {
        result = 1;
    }

    return result;

}

int main()
{
    int num;
    unsigned long long result;

    printf("Enter a positieve integer: ");

    scanf("%i", &num);

    result = recursion(num);

    printf("Factorial of %i is: %llu", num, result);

    return 0;
}
