#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findPermutations(string &str, int idx)
{
    static int n = (int)str.size();
    if (idx == n)
    {
        cout << str << endl;
        return;
    }

    for (int i = idx; i < n; i++)
    {
        swap(str[i], str[idx]);
        findPermutations(str, idx + 1);
        swap(str[i], str[idx]);
    }
}

int main()
{
    string str = "Hey";
    findPermutations(str, 0);
}