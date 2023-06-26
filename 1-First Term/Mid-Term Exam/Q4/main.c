#include "stdio.h"

int reverse(int num);
int main()
{
    int num;
    printf ("Enter the number : ");
    scanf ("%d",&num);
    num = reverse (num);
    printf("reversed number is : %d",num);
  
}
int reverse(int num)
{
    int rev,new_num=0;
   while (num!=0)
   {
    rev=num%10;
    num/=10;
    new_num=new_num*10+rev;
   }
   return new_num;
}