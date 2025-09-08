#include <iostream>
#include <vector>
using namespace std;

int secondSmallest(vector<int> arr)
{
    int small = arr[0], secondSmall = arr[1];

    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] < small)
        {
            secondSmall = small;
            small = arr[i];
        }
        else if (arr[i] < secondSmall && arr[i] != small)
            secondSmall = arr[i];
    }

    return secondSmall;
}

int secondLargest(vector<int> arr)
{
    int max = arr[0], secondMax = arr[1];
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            secondMax = max;
            max = arr[i];
        }
        else if (arr[i] > secondMax && arr[i] != max)
            secondMax = arr[i];
    }

    return secondMax;
}

int main()
{
    vector<int> arr = {5, 2, 4, 2, 22, 33, 4, 5};

    int second_max = secondLargest(arr);
    int second_min = secondSmallest(arr);

    cout << "Second Largest = " << second_max << endl;
    cout << "Second Smallest = " << second_min << endl;
}