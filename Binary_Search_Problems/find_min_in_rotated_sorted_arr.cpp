#include <iostream>
#include <vector>
using namespace std;

int findMinInRotatedSortedArr(vector<int> arr)
{
    int start = 0, end = arr.size() - 1, mid;

    while (start < end)
    {
        mid = (start + end) / 2;

        if (arr[mid] > arr[end])
            start = mid + 1;

        else
            end = mid;
    }

    return arr[start];
}

void displayArr(vector<int> arr)
{
    cout << "Elements = ";
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    displayArr(arr);

    int min = findMinInRotatedSortedArr(arr);

    cout << "Minimum element in the given rotated sorted array = " << min;
}