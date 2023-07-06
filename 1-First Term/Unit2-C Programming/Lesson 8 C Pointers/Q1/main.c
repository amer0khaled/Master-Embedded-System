
#include <stdio.h>

int main()
{
	int m = 29;
	int * ptr;

	printf("Address of m: %p\n", &m);
	printf("Value of m: %d\n", m);

	ptr = &m;

	printf("Address of Pointer: %p\n", &ptr);
	printf("Address that Pointer points to: %p\n", ptr);
	printf("Content of Pointer: %d\n", *ptr);

	m = 34;

	printf("Address that Pointer points to: %p\n", ptr);
	printf("Content of Pointer: %d\n", *ptr);

	*ptr = 7;

	printf("Address of m: %p\n", &m);
	printf("Value of m: %d\n", m);

	return 0;

}