#include <stdio.h>
#include <math.h>

int isArmstrongNumber(int number)
{
    if (number == 0)
        return 1;

    int count = 0, temp = number, lastDigit, sum = 0;

    while (temp > 0)
    {
        count++;
        temp /= 10;
    }

    temp = number;

    while (temp > 0)
    {
        lastDigit = temp % 10;
        sum = sum + (int)powf(lastDigit, count);
        temp /= 10;
    }

    if (sum == number)
        return 1;

    return 0;
}

int main()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    if (isArmstrongNumber(n))
        printf("%d is an Armstrong number.", n);
    else
        printf("%d is not an Armstrong number.", n);
}