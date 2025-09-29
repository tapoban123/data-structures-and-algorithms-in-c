#include <iostream>
#include <vector>
using namespace std;

vector<int> SelectionSort(vector<int> arr)
{
    int temp, min;
    for (int i = 0; i < (int)arr.size() - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < (int)arr.size(); j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    return arr;
}

int BinarySearch(vector<int> arr, int k)
{
    int start = 0, end = arr.size(), mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == k)
            return mid;
        else if (k > arr[mid])
            start = mid + 1;
        else if (k < arr[mid])
            end = mid - 1;
    }
    return -1;
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
    int key;
    vector<int> arr = {1, 6, 3, 4, 5, 2, 1, 2};

    arr = SelectionSort(arr);
    displayArr(arr);

    cout << "Enter an element: ";
    cin >> key;
    
    int keyFound = BinarySearch(arr, key);
    if (keyFound == -1)
        cout << key << " not found in array.";
    else
        cout << key << " found at index " << keyFound;
}
