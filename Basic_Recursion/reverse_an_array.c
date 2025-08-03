#include <stdio.h>

void reverseArray(int arr[], int n)
{
    if (n == 0)
        return;

    printf("%d ", arr[n - 1]);
    reverseArray(arr, n - 1);
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter an element: ");
        scanf("%d", &arr[i]);
    }

    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nReversed Array: ");
    reverseArray(arr, n);
}