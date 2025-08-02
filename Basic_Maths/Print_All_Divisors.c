#include <stdio.h>
#include <math.h>

void findAllDivisors(int number)
{
    for (int i = 1; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            printf("%d ", i);
            if (number / i != i)
                printf("%d ", number / i);
        }
    }
}

int main()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    findAllDivisors(n);
}