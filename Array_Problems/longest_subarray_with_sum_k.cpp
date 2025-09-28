#include <iostream>
#include <vector>
using namespace std;

int findLongestSubArray(vector<int> arr, int k)
{
    // vector<int> subArray = {};
    int sum = 0, length = 0, tempLength;

    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        sum = 0;
        tempLength = 0;
        for (size_t j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            tempLength += 1;

            if (sum == k)
            {
                if (tempLength > length)
                {
                    length = tempLength;
                }
                sum = 0;
                tempLength = 0;
            }
        }
    }

    return length;
}

void displayArr(vector<int> arr)
{
    cout << "Elements are: ";
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 3, 3, 7, 2, 1, 2, 2, 2, 2, 2};
    int k = 6;

    displayArr(arr);

    int longestSubarray = findLongestSubArray(arr, k);

    cout << "Value of k = " << k << "\n";

    cout << "Longest Subarray = " << longestSubarray;
}