#include <stdio.h>

#define Pi 3.14

int main()
{	
	double radius;

	printf("Enter the radius: ");

	scanf("%lf", &radius);

	printf("Area = %lf m^2", Pi * radius * radius);

	return 0;
}