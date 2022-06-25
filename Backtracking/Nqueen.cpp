#include <iostream>
using namespace std;
int board[11][11];
bool isPossible(int n, int row, int col)
{
    //for columns
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    //for left diagonal
    for (int i = row - 1, j = col - 1; i >= 0, j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    //for right diagonal
    for (int i = row - 1, j = col + 1; i >= 0, j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
void nQueens(int n, int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isPossible(n, row, i))
        {
            board[row][i] = 1;
            nQueens(n, row + 1);
            board[row][i] = 0;
        }
    }
    return;
}
int main()
{

    int n;
    cin >> n;
    nQueens(n, 0);
    return 0;
}