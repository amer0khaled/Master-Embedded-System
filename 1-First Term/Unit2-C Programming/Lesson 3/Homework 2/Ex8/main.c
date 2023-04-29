#include<stdio.h>

int main()
{
    float operand1;
    float operand2;
    char operator;


    printf("Enter two operands: ");
    scanf("%f%f", &operand1, &operand2);

    fflush(stdin);
    fflush(stdout);

    printf("Enter operator either + or - or * or /: ");
    scanf("%c", &operator);

    switch (operator)
    {
    case '+':
        printf("%f + %f = %f", operand1, operand2, operand1 + operand2);
        break;

    case '-':
        printf("%f - %f = %f", operand1, operand2, operand1 - operand2);
        break;

    case '*':
        printf("%f * %f = %f", operand1, operand2, operand1 * operand2);
        break;

    case '/':
        printf("%f / %f = %f", operand1, operand2, operand1 / operand2);
        break;

    default:
        printf("Wrong operator");
        break;
    }

    return 0;
}
