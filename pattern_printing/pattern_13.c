#include <stdio.h>

int main()
{
    int n, count = 1;
    printf("Enter the number of lines: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d ", count);
            count++;
        }
        printf("\n");
    }
}