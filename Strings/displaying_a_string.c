#include <stdio.h>

int main()
{
    char str[] = "Hello World";
    int i = 0;

    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }
}