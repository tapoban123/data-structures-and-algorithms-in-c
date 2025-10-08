#include <iostream>
#include <vector>
using namespace std;

int findLastElementIndex(vector<int> arr, int k)
{
    int low = 0, high = arr.size() - 1, mid, lastIndex = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            lastIndex = mid;
            low = mid + 1;
        }
        else if (arr[mid] < k)
            low = mid + 1;
        else if (arr[mid] > k)
            high = mid - 1;
    }
    return lastIndex;
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
    vector<int> arr = {1, 4, 5, 7, 7, 7, 9, 10, 11, 11, 11, 11};
    displayArr(arr);
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    int lastIndex = findLastElementIndex(arr, k);
    if (lastIndex == -1)
        cout << "Element not found in array.";
    else
        cout << "The last occurrence of " << k << " = " << lastIndex;
}