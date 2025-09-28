#include <iostream>
#include <vector>
using namespace std;

int findLongestSubArrayBruteForce(vector<int> arr, int k)
{
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

// int findLongestSubarrayBetterApproach(vector<int> arr, int k)
// {
//     map<int, int> preSumMap = {};
//     int sum = 0;
//     int maxLen = 0;

//     for (int i = 0; i < (int)(arr.size()); i++)
//     {
//         sum += arr[i];
//         if (sum == k)
//         {
//             if (i + 1 > maxLen)
//                 maxLen = i + 1;
//         }

//         int rem = sum - k;
//         if (preSumMap.find(rem) != preSumMap.end())
//         {
//             int len = i - preSumMap[rem];
//             if (len > maxLen)
//                 maxLen = len;
//         }

//         if (preSumMap.find(sum) == preSumMap.end())
//             preSumMap[sum] = i;
//     }

//     return maxLen;
// }

int findLongestSubarrayOptimalApproach(vector<int> arr, int k)
{
    int left = 0, right = 0;
    int sum = arr[0];
    int n = arr.size();
    int maxLen = 0;

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left++];
        }

        if (sum == k)
        {
            int len = right - left + 1;
            if (len > maxLen)
                maxLen = len;
        }

        right++;
        if (right < n)
            sum += arr[right];
    }

    return maxLen;
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
    vector<int> arr = {1, 1, 1, 3, 3, 7, 2, 1, 2, 2};
    int k = 12;

    displayArr(arr);

    int longestSubarray = findLongestSubarrayOptimalApproach(arr, k);

    cout << "Value of k = " << k << "\n";

    cout << "Longest Subarray = " << longestSubarray;
}