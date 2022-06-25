#include <iostream>
using namespace std;
int maze[19][19];
void mazePuzzle(int n, int **output, int row, int col)
{
    if (row == n - 1 && col == n - 1)
    {
        output[row][col] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << output[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }
    if (row > n - 1 || col > n - 1 || row < 0 || col < 0 || maze[row][col] == 0 || output[row][col] == 1)
    {
        return;
    }
    output[row][col] = 1;
    mazePuzzle(n, output, row, col + 1);
    mazePuzzle(n, output, row - 1, col);
    mazePuzzle(n, output, row, col - 1);
    mazePuzzle(n, output, row + 1, col);
    output[row][col] = 0;
    return;
}
int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    int **output = new int *[n];
    for (int i = 0; i < n; i++)
    {
        output[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            output[i][j] = 0;
        }
    }
    mazePuzzle(n, output, 0, 0);
    return 0;
}
