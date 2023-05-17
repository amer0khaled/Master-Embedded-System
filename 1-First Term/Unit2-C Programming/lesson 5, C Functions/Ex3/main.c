#include<stdio.h>
#include<string.h>

void reverse_str(char *ptr);
int length;
int main()
{
    char ptr[50];

    printf("Enter a sentence: ");

    gets(ptr);

    length = strlen(ptr) - 1;

    reverse_str(ptr + length);

    return 0;
}

void reverse_str(char *ptr)
{
    printf("%c", *ptr);

    ptr--;
    length--;

    if(length >= 0)
    {
        reverse_str(ptr);
    }

}