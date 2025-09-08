#include <iostream>
using namespace std;
#include <vector>

vector<int> leftRotateArr(vector<int> arr, int rotations)
{
    int ele;
    for (int j = 0; j < rotations; j++)
    {
        ele = arr[0];

        for (size_t i = 0; i < arr.size() - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[arr.size() - 1] = ele;
    }

    return arr;
}

void displayArr(vector<int> arr)
{
    cout << "Elements = ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int rotations;

    vector<int> arr = {1, 2, 3, 4, 5};
    displayArr(arr);

    cout << "Enter no. of rotations: ";
    cin >> rotations;

    arr = leftRotateArr(arr, rotations);
    displayArr(arr);
}