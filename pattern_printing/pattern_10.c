#include <stdio.h>

int main()
{

    int n;
    printf("Enter number of lines: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            printf("*");

        printf("\n");
    }

    for (int j = 0; j < n - 1; j++)
    {
        for (int i = n - 1 - j; i > 0; i--)
            printf("*");

        printf("\n");
    }
}