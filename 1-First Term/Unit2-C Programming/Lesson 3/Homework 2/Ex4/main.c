#include<stdio.h>

#define READ_BIT(NUM, BIT) NUM&(1<<BIT)

int main()
{
   float num;

   printf("Enter a number: ");

   scanf("%f", &num);

   if(num < 0)
   {
        printf("%f is negative.", num);
   }
   else if (num > 0)
   {
        printf("%f is positive.", num);
   }
   else
   {
        printf("You entered zero.");
   }
   
    return 0;
}