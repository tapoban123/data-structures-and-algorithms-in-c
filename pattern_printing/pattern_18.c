#include <stdio.h>

int main()
{
    const char alphabets[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int n;
    printf("Enter the number of lines: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i; j < n; j++)
        {
            printf("%c ", alphabets[j]);
        }
        printf("\n");
    }
}