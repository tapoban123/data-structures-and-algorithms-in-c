#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int start, int mid, int end)
{
    int i = start, j = mid + 1;
    vector<int> temp;
    int inversionCount = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
        {
            temp.push_back(arr[j++]);
            inversionCount += mid - i + 1;
        }
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= end)
        temp.push_back(arr[j++]);

    for (int k = 0; k < (int)temp.size(); k++)
        arr[k + start] = temp[k];

    return inversionCount;
}

int mergeSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        int leftInversionCount = mergeSort(arr, start, mid);
        int rightInversionCount = mergeSort(arr, mid + 1, end);
        int currentInversionCount = merge(arr, start, mid, end);

        return leftInversionCount + rightInversionCount + currentInversionCount;
    }

    return 0;
}

int main()
{
    vector<int> arr = {6, 3, 5, 2, 7};

    int inversionCount = mergeSort(arr, 0, arr.size() - 1);

    cout << "Inversion Count = " << inversionCount;
}