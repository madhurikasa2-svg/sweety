#include <stdio.h>

int main()
{
    int num, i, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 0)
        printf("Number is Positive\n");
    else if (num < 0)
        printf("Number is Negative\n");
    else
        printf("Number is Zero\n");

    if (num % 2 == 0)
        printf("Number is Even\n");
    else
        printf("Number is Odd\n");

    if (num <= 1)
    {
        isPrime = 0;
    }
    else
    {
        for (i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
            {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime)
        printf("Number is Prime\n");
    else
        printf("Number is Not Prime\n");

    return 0;
}

