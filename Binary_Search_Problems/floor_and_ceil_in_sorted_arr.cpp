#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<string, int> findFloorAndCeil(vector<int> arr, int k)
{
    int low = 0, high = arr.size() - 1, mid, floor, ceil;
    map<string, int> values;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == k)
        {
            floor = arr[mid - 1];
            ceil = arr[mid + 1];
            values = {{"floor", floor}, {"ceil", ceil}};
            return values;
        }
        else if (k < arr[mid])
        {
            high = mid - 1;
        }
        else if (k > arr[mid])
        {
            low = mid + 1;
        }
    }

    values = {{"floor", arr[low - 1]}, {"ceil", arr[high + 1]}};
    return values;
}

int main()
{
    vector<int> arr = {1, 2, 4, 7, 8, 8, 10};
    int x = 9;

    map<string, int> values = findFloorAndCeil(arr, x);

    cout << "Floor = " << values["floor"] << " and " << "Ceil = " << values["ceil"];
}