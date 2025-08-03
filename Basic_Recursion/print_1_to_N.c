#include <stdio.h>

void print_1_To_N(int n)
{
    if (n == 0)
        return;

    print_1_To_N(n - 1);
    printf("%d ", n);
}

int main()
{
    print_1_To_N(10);
}