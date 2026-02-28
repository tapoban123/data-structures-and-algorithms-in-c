#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(vector<string> &board, int n, int row, int col)
{
    // Checking horizontally
    for (int i = 0; i < n; i++)
        if (board[row][i] == 'Q')
            return false;

    // Checking vertically
    for (int i = 0; i < n; i++)
        if (board[i][col] == 'Q')
            return false;

    // Checking left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // Checking right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void placeNQueens(vector<string> board, int n, int row, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isValid(board, n, row, i))
        {
            board[row][i] = 'Q';
            placeNQueens(board, n, row + 1, ans);
            board[row][i] = '.';
        }
    }
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    placeNQueens(board, n, 0, ans);

    if (ans.empty())
    {
        cout << "No possible solutions." << endl;
        return -1;
    }

    for (int count = 0; count < n; count++)
    {
        cout << "Solution Board " << count + 1 << endl;
        vector<string> val = ans[count];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (val[i][j] == '.')
                    cout << " ";
                else
                    cout << val[i][j];
                cout << " | ";
            }

            cout << endl;
        }
        cout << "\n\n";
    }
}