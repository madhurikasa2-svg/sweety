#include <stdio.h>

int main()
{
    char str[100];
    int i, length = 0;
    int vowels = 0;
    int isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    while (str[length] != '\0')
    {
        length++;
    }

    printf("Reversed string: ");
    for (i = length - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");

    for (i = 0; i < length; i++)
    {
        char ch = str[i];

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            vowels++;
        }
    }

    printf("Number of vowels: %d\n", vowels);

    for (i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - i - 1])
        {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("The string is a Palindrome\n");
    else
        printf("The string is Not a Palindrome\n");

    return 0;
}
