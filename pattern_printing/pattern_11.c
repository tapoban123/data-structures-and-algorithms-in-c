#include <stdio.h>

int main()
{
    int n, start;
    printf("Enter number of lines: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            start = 0;
        else
            start = 1;

        for (int j = 0; j < i; j++)
        {
            printf("%d", start);
            start = 1 - start;
            
            // if (i % 2 == 0)
            // {

            //     if (j % 2 != 0)
            //         printf("1");
            //     else
            //         printf("0");
            // }
            // else
            // {
            //     if (j % 2 == 0)
            //         printf("1");
            //     else
            //         printf("0");
            // }
        }

        printf("\n");
    }
}