// A Diamond

#include <stdio.h>

int main()
{
    int n, count = 1;
    printf("Enter the number of lines: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i + count; k++)
        {
            printf("*");
        }

        printf("\n");
        count++;
    }

    count = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < n - i + count; k++)
        {
            printf("*");
        }
        printf("\n");
        count--;
    }
}