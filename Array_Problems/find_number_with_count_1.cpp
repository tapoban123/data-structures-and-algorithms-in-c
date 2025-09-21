#include <iostream>
#include <vector>
using namespace std;

vector<int> InsertionSort(vector<int> arr)
{
    int j, temp;
    for (size_t i = 0; i < arr.size(); i++)
    {
        j = i;

        while (j > 0 && arr[j - 1] > arr[j])
        {
            temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    return arr;
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
    vector<int> arr = {1, 8, 3, 1, 3};
    displayArr(arr);

    arr = InsertionSort(arr);
    displayArr(arr);

    int elementWithCount1 = 0;

    for (int i : arr)
        elementWithCount1 ^= i;

    cout << "Element having count 1 = " << elementWithCount1;
}
