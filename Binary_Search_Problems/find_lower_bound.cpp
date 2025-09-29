#include <iostream>
#include <vector>
using namespace std;

vector<int> isArraySorted(vector<int> arr)
{
    bool isSorted = true;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp;

                isSorted = false;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        if (isSorted)
            break;
    }

    return arr;
}

int findLowerBound(vector<int> arr, int k)
{
    int n = (int)arr.size(), ans = n, start = 0, end = n, mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == k)
        {
            ans = mid;
            return ans;
        }
        else if (arr[mid] > k)
        {
            end = mid - 1;
            ans = mid;
        }
        else if (arr[mid] < k)
            start = mid + 1;
    }

    if (ans >= n)
        return arr.size();

    return ans;
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
    vector<int> arr = {1, 3, 4, 9, 7};

    arr = isArraySorted(arr);
    displayArr(arr);

    int k;
    cout << "Enter an element: ";
    cin >> k;

    int lowerBound = findLowerBound(arr, k);

    cout << "Lower bound of " << k << " = " << lowerBound;
}