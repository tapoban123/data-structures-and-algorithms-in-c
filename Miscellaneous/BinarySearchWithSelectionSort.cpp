#include <iostream>
#include <vector>
using namespace std;

vector<int> SelectionSort(vector<int> arr)
{
    int min, temp;
    for (size_t i = 0; i < arr.size(); i++)
    {
        min = i;

        for (size_t j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
            {
                temp = arr[j];
                arr[j] = arr[min];
                arr[min] = temp;
            }
        }
    }
    return arr;
}

int BinarySearch(vector<int> arr, int q)
{
    int start = 0, end = arr.size(), mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == q)
            return mid;

        else if (arr[mid] < q)
            start = mid + 1;
        else if (arr[mid] > q)
            end = mid - 1;
    }

    return -1;
}

void displayArr(vector<int> arr)
{
    cout << "Elements = ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int q;
    vector<int> arr = {9, 3, 21, 5, 1, 9, 4};
    displayArr(arr);
    arr = SelectionSort(arr);
    displayArr(arr);

    cout << "Enter an element: ";
    cin >> q;

    int searchIndex = BinarySearch(arr, q);

    if (searchIndex == -1)
        cout << q << " does not exist is the given array.";
    else
        cout << q << " exists in the given array at index " << searchIndex;
}