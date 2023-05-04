#include<stdio.h>

int main()
{
    char User_Input;

    printf("Enter a character: ");

    scanf("%c", &User_Input);

    printf("ASCII value of %c = %i", User_Input, User_Input);



    return 0;
}