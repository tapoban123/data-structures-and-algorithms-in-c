#include <iostream>
#include <vector>
using namespace std;

int findLargest(vector<int> arr)
{
    int max = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }
    return max;
}

int main()
{
    vector<int> arr = {4, 5, 2, 12, 3, 4};
    int max = findLargest(arr);
    cout << "Max = " << arr[max] << endl;
}