#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "()(()())(())";
    string outputStr = "";
    int count = 0;

    for (char ch : str)
    {
        if (ch == '(')
        {
            count++;
            if (count > 1)
                outputStr += '(';
        }
        else if (ch == ')')
        {
            if (count > 1)
                outputStr += ')';
            count--;
        }
    }

    cout << outputStr;
}
