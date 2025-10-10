#include <iostream>
#include <vector>
using namespace std;

int countOccurences(vector<int> arr, int k)
{
    int start = 0, end = arr.size() - 1, mid, count = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == k)
        {
            count++;
            start = mid + 1;
        }
        else if (arr[mid] > k)
            end = mid - 1;
        else if (arr[mid] < k)
            start = mid + 1;
    }

    return count;
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
    vector<int> arr = {2, 3, 5, 6, 6, 9, 9, 9};
    displayArr(arr);

    int k;
    cout << "Enter the element you want to count: ";
    cin >> k;

    int count = countOccurences(arr, k);

    if (count == 0)
        cout << k << " is not found in the array.";
    else
        cout << k << " is present " << count << " times in the array.";
}