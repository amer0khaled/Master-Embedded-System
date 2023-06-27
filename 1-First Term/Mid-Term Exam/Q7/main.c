
/*sum numbers from 1 to n*/

#include<stdio.h>

int n;

int main()
{

    long long sum = 0;

    printf("Enter n: ");

    scanf("%d", &n);

    sum = (n*(n+1))/2;

    printf("sum = %lld", sum);

    return 0;

}
