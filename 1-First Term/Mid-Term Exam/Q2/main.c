#include<stdio.h>
#include<math.h>

/*get sqrt of a number*/

void get_square_root(int num);

int main()
{
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);

    get_square_root(num);

    return 0;
}

void get_square_root(int num)
{
    printf("result = %f", sqrt(num));
}
