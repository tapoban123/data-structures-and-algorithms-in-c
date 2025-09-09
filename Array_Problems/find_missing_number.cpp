#include <iostream>
#include <vector>
using namespace std;

int findMissingEle(int n, vector<int> arr)
{
    int sumOfNNumbers = n * (n + 1) / 2;
    int sum = 0;

    for (int i : arr)
    {
        sum += i;
    }

    int missingNumber = sumOfNNumbers - sum;
    return missingNumber;
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
    int n = 5;
    vector<int> arr = {1, 2, 4, 5};
    displayArr(arr);

    int missingEle = findMissingEle(n, arr);
    cout << "Missing element = " << missingEle;
}