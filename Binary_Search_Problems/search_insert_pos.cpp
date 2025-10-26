#include <iostream>
#include <vector>
using namespace std;

int searchInsertPos(vector<int> arr, int x)
{
    int low = 0, high = arr.size() - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] < x)
            low = mid + 1;
        else if (arr[mid] > x)
            high = mid - 1;
    }

    return low;
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
    vector<int> arr = {1, 2, 3, 4, 7};
    int x;
    displayArr(arr);

    cout << "Enter element to insert: ";
    cin >> x;

    int pos = searchInsertPos(arr, x);
    cout << "Position to insert " << x << " = " << pos;
}