#include <stdio.h>

// Using Euclidean Formula
int findGcd(int num1, int num2)
{
    while (num1 > 0 && num2 > 0)
    {
        if (num1 > num2)
            num1 = num1 % num2;
        else
            num2 = num2 % num1;
    }

    if (num1 == 0)
        return num2;
    return num1;
}

int main()
{
    int n1, n2;
    printf("Enter first integer: ");
    scanf("%d", &n1);

    printf("Enter second integer: ");
    scanf("%d", &n2);

    int gcd = findGcd(n1, n2);

    printf("GCD of %d and %d = %d", n1, n2, gcd);
}