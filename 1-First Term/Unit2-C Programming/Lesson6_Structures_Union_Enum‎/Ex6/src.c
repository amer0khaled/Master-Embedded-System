#include <stdio.h>

union UnionJob
{
	char name [32] ;
	float salary;
	int worker_no;

} U;

struct Job
{
	char name [32];
	float salary;
	int worker_no;

} S;

int main ()
{
	printf ("Size of the union is: %d\n", sizeof (U));
	printf ("\nSize of the structure is: %d\n", sizeof (S));

	return 0;
}

/*

	sizeof(union) = size of biggest member = 32 byte.

	sizeof(struct) -> applying packing = 32 + 4 + 4 = 40 byte.


*/