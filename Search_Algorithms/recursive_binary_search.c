#include <stdio.h>

int rBinarySearch(int *, int, int, int);

int rBinarySearch(int A[], int key, int low, int high)
{

    if (low == high)
    {
        if (A[low] == key)
            return low;
        else
            return -1;
    }
    else
    {
        int mid = (low + high) / 2;

        if (A[mid] == key)
            return mid;

        if (A[mid] > key)
            return rBinarySearch(A, key, low, mid - 1);
        else
            return rBinarySearch(A, key, mid + 1, high);
    }
}

int main()
{
    int key, n = 10, foundIndex;
    int sorted_array[] = {3, 7, 12, 18, 25, 31, 42, 56, 67, 79};

    printf("Enter key: ");
    scanf("%d", &key);

    foundIndex = rBinarySearch(sorted_array, key, 0, n);

    if (foundIndex == -1)
        printf("%d not found in the array.", key);
    else
        printf("%d found at index %d", key, foundIndex + 1);

    return 0;
}
