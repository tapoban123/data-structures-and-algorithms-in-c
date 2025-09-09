#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> arr, int q)
{
    int i = 0;
    int n = arr.size();
    arr.push_back(q);

    for (; arr[i] != q; i++)
        ;

    if (i == n)
        return -1;

    return i;
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
    int q;
    vector<int> arr = {5, 4, 3, 2, 1};
    displayArr(arr);

    cout << "Enter search element: ";
    cin >> q;

    int eleIndex = linearSearch(arr, q);
    if (eleIndex == -1)
        cout << q << " not found in the array.";
    else
        cout << q << " found at index " << eleIndex;
}