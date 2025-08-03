#include <stdio.h>

void print_N_to_1(int n)
{
    if (n == 0)
        return;

    printf("%d ", n);
    print_N_to_1(n - 1);
}

int main()
{
    print_N_to_1(10);
}