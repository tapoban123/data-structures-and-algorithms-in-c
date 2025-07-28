#include <stdio.h>

int main()
{
    int n, count;
    printf("Enter number of lines: ");
    scanf("%d", &n);

    count = n - 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d", j + 1);
        }

        for (int k = 0; k < n - i + count; k++)
        {
            printf(" ");
        }

        for (int m = i; m > 0; m--)
        {
            printf("%d", m);
        }
        count--;
        printf("\n");
    }
}