#include <stdio.h>

int isPrime(int num)
{
    int count = 0;
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
            if (num / i != i)
                count++;
        }
    }

    if (count == 2)
        return 1;

    return 0;
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPrime(n))
        printf("%d is a Prime number.", n);
    else
        printf("%d is not a Prime number.", n);
}