#include <iostream>
#include <vector>
using namespace std;

int findMinInRotatedSortedArr(vector<int> arr) {}

void displayArr(vector<int> arr)
{
    cout << "Elements = ";
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    displayArr(arr);

    int min = findMinInRotatedSortedArr(arr);

    cout << "Minimum element in the given rotated sorted array = " << min;
}