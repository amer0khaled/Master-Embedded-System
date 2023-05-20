#include<stdio.h>

#define CLR_BIT(num, bit_num) num &= ~(1<<bit_num) 

void main()
{   
    int Num;
    int Bit_Num;
  
    printf("Enter The Number: ");
    scanf("%i", &Num);

    printf("Enter The Bit Number To Clear It: ");
    scanf("%i", &Bit_Num);

    printf("Number After Clearing The Bit: %i", CLR_BIT(Num, Bit_Num));

}
