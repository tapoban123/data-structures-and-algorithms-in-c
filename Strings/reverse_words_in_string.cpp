#include <iostream>
#include <string>
using namespace std;

// TODO: ALGORITHM STILL IN PROGRESS.
int main()
{
    string str = "My name              iss tapo ban    ray";
    string resultStr = "";
    string word = "";

    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
            continue;

        int j = i;
        while (str[j] != ' ')
        {
            j--;
        }

        for (int k = j + 1; k <= i; k++)
            word += str[k];

        if (resultStr.size() > 0)
            resultStr += ' ';
        resultStr += word;
        word = "";
        i = j + 1;
    }

    cout << resultStr;
}