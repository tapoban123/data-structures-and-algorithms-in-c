#include <iostream>
#include <vector>
using namespace std;

vector<int> InsertionSort(vector<int> arr)
{
    int temp, j, n = arr.size();

    for (int i = 0; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    return arr;
}

int findUpperBound(vector<int> arr, int k)
{
    int ans, n = arr.size(), start = 0, end = n, mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == k)
            return mid;
        else if (arr[mid] > k)
            end = mid - 1;
        else if (arr[mid] < k)
        {
            ans = mid;
            start = mid + 1;
        }
    }
    if (ans >= 0)
        return ans;
    return n;
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
    vector<int> arr = {10, 1, 5, 2, 3, 4, 9};
    arr = InsertionSort(arr);
    displayArr(arr);

    int k;
    cout << "Enter an element: ";
    cin >> k;

    int upperBound = findUpperBound(arr, k);
    cout << "Upper Bound of " << k << " = " << upperBound;
}