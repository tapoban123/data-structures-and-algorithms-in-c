#include <iostream>
using namespace std;

void Merge(int arr[], int low, int mid, int high);

void MergeSort(int arr[], int low, int high)
{
    if (low == high)
        return;

    int mid = (low + high) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
}

void Merge(int arr[], int low, int mid, int high)
{
    int left = low, right = mid + 1, temp_i = 0;
    int temp[high];

    while (left <= mid && right <= high)
        if (arr[left] < arr[right])
            temp[temp_i++] = arr[left++];
        else
            temp[temp_i++] = arr[right++];

    while (left <= mid)
        temp[temp_i++] = arr[left++];

    while (right <= high)
        temp[temp_i++] = arr[right++];

    int i = low;
    for (; i <= high; i++)
        arr[i] = temp[i - low];
}

void displayArr(int arr[], int n)
{
    cout << "Elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 6;
    int arr[] = {9, 4, 5, 1, 23, 6};
    
    displayArr(arr, n);
    MergeSort(arr, 0, n - 1);
    displayArr(arr, n);
}