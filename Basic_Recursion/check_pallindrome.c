#include <stdio.h>

int isPallindrome(int n, int input, int reversed)
{
    if (n == 0)
    {
        if (reversed == input)
            return 1;

        return 0;
    }

    return isPallindrome((n / 10), input, (reversed * 10) + (n % 10));
}

int main()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    int isPall = isPallindrome(n, n, 0);

    if (isPall)
        printf("%d is a Pallindrome number.", n);
    else
        printf("%d is not a Pallindrome number.", n);
}