#include <stdio.h>

int binarySearch(int *, int, int);

int binarySearch(int A[], int n, int key)
{

    int low = 0, high = n, mid;

    while (A[low] <= A[high])
    {
        mid = (low + high) / 2;

        if (A[mid] == key)
            return mid;

        else if (A[mid] > key)
            high = mid - 1;

        else if (A[mid] < key)
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int key, n = 10, foundIndex;
    int sorted_array[] = {3, 7, 12, 18, 25, 31, 42, 56, 67, 79};

    printf("Enter key: ");
    scanf("%d", &key);

    foundIndex = binarySearch(sorted_array, n, key);

    if (foundIndex == -1)
        printf("%d not found in array.", key);
    else
        printf("%d found at index: %d", key, foundIndex + 1);
}
