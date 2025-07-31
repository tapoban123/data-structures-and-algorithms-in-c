#include <stdio.h>

int isPallindrome(int number)
{
    int temp = number, revNum = 0, lastDigit;

    while (number > 0)
    {
        lastDigit = number % 10;
        number /= 10;
        revNum = revNum * 10 + lastDigit;
    }

    if (temp == revNum)
        return 1;

    return 0;
}

int main()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    if (isPallindrome(n))
        printf("%d is a Pallindrome number.", n);
    else
        printf("%d is not a Pallindrome number.", n);
}