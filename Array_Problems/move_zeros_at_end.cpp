#include <iostream>
#include <vector>
using namespace std;

void swap(int *val1, int *val2)
{
    *val1 = *val1 + *val2;
    *val2 = *val1 - *val2;
    *val1 = *val1 - *val2;
}

vector<int> moveZerosToEnd(vector<int> arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            for (size_t j = i; j < arr.size() - 1; j++)
            {
                swap(&arr[j], &arr[j + 1]);
            }
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
    vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 1};
    displayArr(arr);

    arr = moveZerosToEnd(arr);

    displayArr(arr);
}
