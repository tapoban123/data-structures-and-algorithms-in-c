#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *, int, int);
void merge(int *, int, int, int);

// Recursive function to divide the array and merge them.
void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);

        merge(A, low, mid, high);
    }
}

// Function to merge two sorted arrays.
void merge(int A[], int low, int mid, int high)
{
    int C[high];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
            C[k++] = A[i++];
        else
            C[k++] = A[j++];
    }

    while (i <= mid)
        C[k++] = A[i++];

    while (j <= high)
        C[k++] = A[j++];

    int x;
    for (x = low; x <= high; x++)
        A[x] = C[x];

    free(C);
}

// Function to display array.
void displayArr(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
}

int main()
{
    int n = 10;
    int arr[] = {100, 23, 5, 523, 3, 32, 55, 3, 90, 1};

    mergeSort(arr, 0, n - 1);
    displayArr(arr, n);
}