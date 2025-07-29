#include <stdio.h>

int countDigits(int number)
{
    int count = 0;
    if (number == 0)
        return 1;

    while (number > 0)
    {
        count++;
        number = number / 10;
    }

    return count;
}

int main()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    int count = countDigits(n);
    printf("Number of digits = %d", count);
}