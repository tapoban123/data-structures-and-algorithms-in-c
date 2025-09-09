#include <iostream>
using namespace std;
#include <vector>

enum RotationDirection
{
    LEFT,
    RIGHT
};

vector<int> rotateArr(vector<int> arr, int rotations, RotationDirection direction)
{
    int ele;
    for (int i = 0; i < rotations; i++)

    {
        switch (direction)
        {
        case RIGHT:

            ele = arr[arr.size() - 1];
            for (size_t j = arr.size() - 1; j > 0; j--)
            {
                arr[j] = arr[j - 1];
            }

            arr[0] = ele;

            break;
        case LEFT:
            ele = arr[0];
            for (size_t i = 0; i < arr.size() - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            arr[arr.size() - 1] = ele;

            break;
        }
    }
    return arr;
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
    int rotations;
    char direction;
    RotationDirection rtnDirection;

    vector<int> arr = {1, 3, 5, 6, 8, 10};
    displayArr(arr);

    cout << "Enter no. of rotations: ";
    cin >> rotations;

    cout << "Enter direction: (R/L) ";
    cin >> direction;

    if (direction == 'R')
        rtnDirection = RotationDirection ::RIGHT;
    else if (direction == 'L')
        rtnDirection = RotationDirection::LEFT;

    arr = rotateArr(arr, rotations, rtnDirection);
    displayArr(arr);
}
