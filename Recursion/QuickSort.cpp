#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int idx = start - 1;
    int pivot = arr[end];

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[idx], arr[j]);
        }
    }

    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

void quickSortArr(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pivotIdx = partition(arr, start, end);
        quickSortArr(arr, start, pivotIdx - 1);
        quickSortArr(arr, pivotIdx + 1, end);
    }
}

int main()
{
    vector<int> arr = {9, 7, 5, 2, 1};
    quickSortArr(arr, 0, arr.size() - 1);

    for (int i : arr)
        cout << i << " ";
}