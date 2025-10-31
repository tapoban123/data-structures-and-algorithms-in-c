#include <iostream>
#include <vector>
using namespace std;

int findPeakElementInArr(vector<int> arr)
{
    int low = 1, high = arr.size() - 2, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;

        if (arr[low] <= arr[mid])
            low = mid + 1;
        else
            high = mid;
    }

    // return arr[mid];
    return -1;
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
    vector<int> arr = {1, 2, 1, 3, 5, 6, 4};
    displayArr(arr);

    int peak = findPeakElementInArr(arr);

    if (peak == -1)
        cout << "No peak element found.";
    else
        cout << "Peak element found in arr = " << arr[peak];
}