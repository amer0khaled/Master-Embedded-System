

/*this EXample is as same as Ex1*/

#include<stdio.h>

#define NUMBER_OF_STUDENT 10

typedef struct S_student
{
    char name[50];
    int roll;
    float marks;

}student;


void PRINT_student(student * ptr)
{   
    int i;

    for(i = 0; i < NUMBER_OF_STUDENT; i++)
    {
        printf("the name of student number %d: %s\n", i+1, ptr[i].name);
        
        printf("the roll number of student number %d: %d\n", i+1, ptr[i].roll);
        
        printf("Enter the marks of student number %d: %f\n", i+1, ptr[i].marks);

        printf("\n=====================================================\n");

    }
}

void READ_student(student * ptr)
{
    int i;

    for(i = 0; i < NUMBER_OF_STUDENT; i++)
    {
        printf("Enter the name of student number %d: ", i+1);
        gets(ptr[i].name);

        fflush(stdin);

        printf("Enter the roll number of student number %d: ", i+1);
        scanf("%d", &(ptr[i].roll));

        fflush(stdin);

        printf("Enter the marks of student number %d: ", i+1);
        scanf("%f", &(ptr[i].marks));

        fflush(stdin);

        printf("\n=====================================================\n");

    }

    PRINT_student(ptr);

}


int main()
{
    student arr[NUMBER_OF_STUDENT];

    READ_student(arr);

    return 0;

}