#include <iostream>
using namespace std;
bool findThePossibleLocation(int **sudoku, int &row, int &col)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool isSafeRow(int **sudoku, int row, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == num)
        {
            return false;
        }
    }
    return true;
}
bool isSafeCol(int **sudoku, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][col] == num)
        {
            return false;
        }
    }
    return true;
}
bool isSafeGrid(int **sudoku, int row, int col, int num)
{
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[i + rowFactor][j + colFactor] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool isSafe(int **sudoku, int row, int col, int num)
{
    return (isSafeRow(sudoku, row, num) && isSafeCol(sudoku, col, num) && isSafeGrid(sudoku, row, col, num));
}
bool sudokuSolver(int **sudoku)
{
    int row, col;
    if (!findThePossibleLocation(sudoku, row, col))
    {
        return true;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(sudoku, row, col, i))
        {
            sudoku[row][col] = i;
            if (sudokuSolver(sudoku))
            {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int **sudoku = new int *[9];
    for (int i = 0; i < 9; i++)
    {
        sudoku[i] = new int[9];
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
        }
    }
    if(sudokuSolver(sudoku)){
        cout<<"true";
        return 0;
    }
    cout<<"false";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}