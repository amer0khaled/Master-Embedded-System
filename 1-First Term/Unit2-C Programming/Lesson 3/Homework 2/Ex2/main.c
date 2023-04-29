 #include<stdio.h>

 int main()
 {
    char alphabet;

    printf("Enter an alphabet: ");
    scanf("%c", &alphabet);

    switch (alphabet)
    {
    case 'a':
    case 'A':
        printf("%c is a vowel.", alphabet);
        break;
    
    case 'e':
    case 'E':
        printf("%c is a vowel.", alphabet);
        break;

    case 'i':
    case 'I':
        printf("%c is a vowel.", alphabet);
        break;

    case 'o':
    case 'O':
        printf("%c is a vowel.", alphabet);
        break;

    case 'u':
    case 'U':
        printf("%c is a vowel.", alphabet);
        break;    

    default:
        printf("%c is a constant.", alphabet);
        break;
    }


    return 0;
 }