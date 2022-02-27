#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n1, m;
    cin >> n1 >> m;
    int a[n1][m];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int n2;
    cin >> n2;
    int b[m][n2];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin >> b[i][j];
        }
    }
    int c[n1][n2], sum = 0, i = 0, j = 0, col = 0, k = 0;
    //Multiplication of matrix
    while (i < n1)
    {
        col = 0, j = 0;
        while (j < n2)
        {
            k = 0;
            while (k < m)
            {
                sum += a[i][k] * b[k][col];
                k++;
            }
            c[i][j] = sum;
            sum = 0;
            col++;
            j++;
        }
        i++;
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
