#include <stdio.h>

// TODO: Needs Rework

int main()
{
    int n, count = 1;
    printf("Enter the number of lines: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            printf(" ");

        for (int k = 0; k < i + 1; k++)
            printf("%d", count + k);

        if (i > 0)
            for (int m = i * 2; m > i; m--)
                printf("%d", m);

        count++;

        printf("\n");
    }
}
