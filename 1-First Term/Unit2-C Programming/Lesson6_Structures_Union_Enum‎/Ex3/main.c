#include<stdio.h>

struct SComplex
{
	double real;
	double imag;

}num1, num2, sum;


void ADD_Complex()
{
	sum.real = num1.real + num2.real;

	sum.imag = num1.imag + num2.imag;
}

void READ_Complex()
{
	printf("Enter a Real number of num1: ");
	scanf("%lf", &num1.real);

	printf("Enter a Imaginary number of num1: ");
	scanf("%lf", &num1.imag);

	printf("Enter a Real number of num2: ");
	scanf("%lf", &num2.real);

	printf("Enter a Imaginary number of num2: ");
	scanf("%lf", &num2.imag);

}

void main()
{	

	READ_Complex();

	ADD_Complex();

	printf("Sum = %lf + j%lf ", sum.real, sum.imag);
}