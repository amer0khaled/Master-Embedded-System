#include<stdio.h>
#include<string.h>

void Check_User_Name(char * Usr_Str, int Str_Len);

void main()
{
    char User_String[50];

    printf("Set The User Name: ");
    gets(User_String);

    Check_User_Name(User_String, strlen(User_String));

}

void Check_User_Name(char * Usr_Str, int Str_Len)
{   
    char i = 0;
    char Entered_User_Name[50];

    printf("Enter The User Name: ");
    gets(Entered_User_Name);

    while(Usr_Str[i] == Entered_User_Name[i])
    {
        i++;
    }

    if(i-1 == Str_Len)
    {
        printf("Correct User Name");
    }
    else
    {
        printf("Wrong User Name");
    }

}