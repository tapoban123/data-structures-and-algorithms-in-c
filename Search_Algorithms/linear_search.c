#include <stdio.h>

int linearSearch(int *, int, int);

int linearSearch(int arr[], int n, int key)
{
    int i;
    arr[n] = key;

    for (i = 0; arr[i] != key; i++)
        ;

    if (i < n)
        return i;

    return -1;
}

int main()
{
    int key, foundIndex, n = 6;
    int arr[] = {3, 5, 1, 6, 7, 10};

    printf("Enter key: ");
    scanf("%d", &key);

    foundIndex = linearSearch(arr, n, key);

    if (foundIndex == -1)
        printf("%d not found in array.", key);
    else
        printf("%d found at index: %d", key, foundIndex + 1);
}