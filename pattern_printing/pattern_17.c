#include <stdio.h>

int main()
{
    const char alphabets[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int n;
    printf("Enter number of lines: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            printf(" ");

        for (int k = 0; k < i + 1; k++)
        {
            printf("%c", alphabets[k]);
        }

        if (i > 0)
            for (int m = i - 1; m >= 0; m--)
                printf("%c", alphabets[m]);
        printf("\n");
    }
}