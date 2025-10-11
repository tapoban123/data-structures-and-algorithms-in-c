#include <iostream>
#include <vector>
using namespace std;

int searchElementInRotatedArr(vector<int> arr, int k)
{
    // Here first step is to find the sorted half
    int low = 0, high = arr.size() - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[low] <= arr[mid])
        {
            // Left is sorted
            if (arr[low] <= k && k <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            // Right is sorted
            if (arr[mid] <= k && k <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
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
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int k;

    displayArr(arr);
    cout << "Enter element to search: ";
    cin >> k;

    int index = searchElementInRotatedArr(arr, k);

    if (index == -1)
        cout << k << " not found in the given array.";
    else
        cout << k << " is found at index " << index;
}