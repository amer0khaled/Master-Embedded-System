
#include "stdio.h"
#include "string.h"

int reverse(char str[],char size);
int main()
{
    char str[100];
    printf ("Enter the name : ");
    gets (str);
    char size = strlen(str)-1;
    reverse(str,size);
}
int reverse(char *str,char size)
{
    char str2[100];
    int i;
    for (i=size;str[i]!=' ';i--)
    {

    }
    for (i++;str[i]!=0;i++)
    printf ("%c",str[i]);
    printf (" ");
    for (i=0;str[i]!=' ';i++)
    printf("%c",str[i]);
}
