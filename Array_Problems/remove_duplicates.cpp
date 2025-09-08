#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> removeDuplicates(vector<int> arr)
{
    map<int, int> noDups = {};

    for (size_t i = 0; i < arr.size(); i++)
    {
        noDups[arr[i]] += 1;
    }

    vector<int> unique = {};

    for (auto i = noDups.begin(); i != noDups.end(); i++)
    {
        unique.push_back(i->first);
    }

    return unique;
}

void displayArr(vector<int> arr)
{
    cout << "Elements = ";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> myArr = {3, 3, 2, 1, 5, 5, 5};
    displayArr(myArr);

    myArr = removeDuplicates(myArr);
    displayArr(myArr);
}