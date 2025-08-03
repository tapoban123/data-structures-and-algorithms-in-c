#include <stdio.h>

int factorial(int n, int fact)
{
    if (n == 1)
        return fact;

    return factorial(n - 1, n * fact);
}

int main()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    int fact = factorial(n, 1);

    printf("%d", fact);
}