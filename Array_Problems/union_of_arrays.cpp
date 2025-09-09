#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> findUnion(vector<int> arr1, vector<int> arr2)
{
    map<int, int> unionMap = {};
    vector<int> unionArr = {};

    for (int i : arr1)
        unionMap[i] += 1;

    for (int j : arr2)
        unionMap[j] += 1;

    for (auto i = unionMap.begin(); i != unionMap.end(); i++)
    {
        unionArr.push_back(i->first);
    }
    return unionArr;
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
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
    vector<int> unionArr;

    displayArr(arr1);
    displayArr(arr2);

    unionArr = findUnion(arr1, arr2);
    displayArr(unionArr);
}