#include<stdio.h>

long long power_number(int base,  int power);

int main()
{
    int base;
    int power;
    long long result;

    printf("Enter base number: ");
    scanf("%i", &base);

    printf("Enter power number (positive integer): ");
    scanf("%i", &power);

    result = power_number(base, power+1);

    printf("%i ^ %i = %lld", base, power, result);

}

long long power_number(int base,  int power)
{   
    if(power > 1)
    {
         power--;

         return (base * power_number(base, power));

    }
    else
    {
        return 1;
    }
          
}