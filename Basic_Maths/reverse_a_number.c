#include <stdio.h>

int reverseNumber(int number)
{
    int revNum = 0, lastDigit;
    while (number > 0)
    {
        lastDigit = number % 10;
        number = number / 10;
        revNum = (revNum * 10) + lastDigit;
    }

    return revNum;
}

int main()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("%d after reverse %d", n, reverseNumber(n));
}