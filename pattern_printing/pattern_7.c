#include <stdio.h>

int main()
{
    int n, count = 1;
    printf("Enter number of lines: ");
    scanf("%d", &n);

    for (int i = 1; i<= n; i++)
    {
        for (int k = n - i; k > 0; k--)
            printf(" ");

        for (int j = 0; j < i + count - 1; j++)
        {
            printf("*");
        }
        printf("\n");
        count++;
    }
}
