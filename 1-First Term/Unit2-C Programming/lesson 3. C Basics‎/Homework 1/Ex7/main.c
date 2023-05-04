#include<stdio.h>

int main()
{
    int a;
    int b;

    printf("Enter value of a: ");
    scanf("%i", &a);


    printf("Enter value of b: ");
    scanf("%i", &b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("After swapping, value of a = %i\n", a);

    printf("After swapping, value of b = %i", b);



    return 0;
}