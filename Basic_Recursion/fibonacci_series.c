#include <stdio.h>

int fib(int n)
{
    if (n <= 1)
        return n;

    int last = fib(n - 1);
    int sLast = fib(n - 2);

    return last + sLast;
}

int main()
{
    int n = 10;
    printf("%d", fib(n));
}