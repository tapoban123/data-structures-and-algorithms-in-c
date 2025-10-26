#include <iostream>
#include <vector>
using namespace std;

int searchSingleEleInSortedArr(vector<int> arr)
{
    int start = 1, n = arr.size(), end = n - 2, mid = -1;

    if (arr[0] != arr[1])
        return 0;

    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    if (n == 1)
        return 0;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
            return mid;

        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 != 0 && arr[mid] == arr[mid - 1]))
            start = mid + 1;

        else
            end = mid - 1;
    }
    return mid;
}

void displayArr(vector<int> arr)
{
    cout << "Elements: ";
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    displayArr(arr);

    int singleEle = searchSingleEleInSortedArr(arr);

    cout << "Single element: " << arr[singleEle];
}