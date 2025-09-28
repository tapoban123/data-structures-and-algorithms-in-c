#include <iostream>
#include <map>
#include <vector>
using namespace std;

int findLongestSubarrayWithSumKIncludingNegatives(vector<int> arr, int k)
{
    map<int, int> preSumMap = {};
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            if (i + 1 > maxLen)
                maxLen = i + 1;
        }

        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            if (len > maxLen)
                maxLen = len;
        }

        if (preSumMap.find(sum) == preSumMap.end())
            preSumMap[sum] = i;
    }

    return maxLen;
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
    vector<int> arr = {8, 8, 0, 0, 1, 5, 5};
    int k = 1;
    displayArr(arr);

    cout << "Value of k = " << k << "\n";

    int subarrayLen = findLongestSubarrayWithSumKIncludingNegatives(arr, k);
    cout << "Length of longest subarray(including zeros & negatives): " << subarrayLen;
}