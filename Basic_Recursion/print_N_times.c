#include <stdio.h>
#include <string.h>

void printNTimes(char str[], int n)
{
    if (n == 0)
        return;

    else
    {
        printf("%s\n", str);

        printNTimes(str, n - 1);
    }
}

int main()
{
    char str[50] = "Hello World";

    printNTimes(str, 10);
}