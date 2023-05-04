#include<stdio.h>

int main()
{   
    char var;

    printf("Enter a character: "); 

    scanf("%c", &var);

    switch (var)
    {
    case 65 ... 90:
    case 97 ... 122:

        printf("%c is an alphabet", var);
        break;
    
    default:

        printf("%c in not an alphabet", var);
        break;
    }

    return 0;
}