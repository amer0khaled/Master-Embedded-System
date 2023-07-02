#include<stdio.h>

struct Sdistance
{
    int feet;
    double inch;
}d1, d2, sum;

void main()
{
    printf("Enter distance d1 in feet: ");
    scanf("%d", &d1.feet);

    printf("Enter distance d1 in inch: ");
    scanf("%lf", &d1.inch);

    printf("Enter distance d2 in feet: ");
    scanf("%d", &d2.feet);

    printf("Enter distance d2 in inch: ");
    scanf("%lf", &d2.inch);

    sum.feet = d1.feet + d2.feet;

    sum.inch = d1.inch + d2.inch;

    while(sum.inch > 12)
    {
        sum.inch -= 12;
        ++sum.feet; 
    }

    printf("Sum of distances: %d\' - %lf\"", sum.feet, sum.inch);

}