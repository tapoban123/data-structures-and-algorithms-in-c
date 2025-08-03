#include <stdio.h>

void printSum(int n, int sum)
{
    if (n == 0)
    {
        printf("%d", sum);
        return;
    }

    printSum(n - 1, sum + n);
}

int main()
{
    printSum(12, 0);
}