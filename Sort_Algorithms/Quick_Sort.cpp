#include <iostream>
using namespace std;

int partitionAlgorithm(int *, int, int);

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partition = partitionAlgorithm(arr, low, high);
        QuickSort(arr, low, partition - 1);
        QuickSort(arr, partition + 1, high);
    }
}

int partitionAlgorithm(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;

        while (arr[j] > pivot && j >= low + 1)
            j--;

        if (i < j)
            swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]);

    return j;
}

void displayArr(int arr[], int n)
{
    cout << "Elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 7;
    int arr[] = {9, 4, 5, 2, 1, 4, 5};

    displayArr(arr, n);
    QuickSort(arr, 0, n - 1);
    displayArr(arr, n);
}