#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findMaxConsecutveOnes(vector<int> arr)
{
    int count = 0, max_count = 0;
    for (int i : arr)
    {
        if (i == 1)
        {
            count++;
            if (max_count < count)
                max_count++;
        }
        else
            count = 0;
    }
    return max_count;
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
    vector<int> arr = {1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};
    displayArr(arr);

    int maxOnes = findMaxConsecutveOnes(arr);
    cout << "Maximum number of consecutive ones = " << maxOnes;
}