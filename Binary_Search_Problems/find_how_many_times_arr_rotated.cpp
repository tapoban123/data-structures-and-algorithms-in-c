#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findHowManyTimesArrRotated(vector<int> arr)
{
    int start = 0, end = arr.size() - 1, mid, ans = INT_MAX;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[start] <= arr[end])
        {
            if (arr[start] < arr[ans])
            {
                ans = start;
                return ans;
            }
        }

        if (arr[start] <= arr[mid])
        {
            if (arr[start] < arr[ans])
            {
                ans = start;
            }
            start = mid + 1;
        }
        else
        {
            if (arr[mid] < arr[ans])
            {
                ans = mid;
            }
            end = mid - 1;
        }
    }

    return ans;
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
    vector<int> arr = {4, 5, 6, 7, 1, 2, 3};
    displayArr(arr);

    int noOfRotations = findHowManyTimesArrRotated(arr);

    cout << "Minimum = " << noOfRotations;
}