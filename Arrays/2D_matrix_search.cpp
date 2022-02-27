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
    int n, m, target;
    cin >> n >> m >> target;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int r = 0, c = m - 1;
    bool status = false;
    while (r < n && c >= 0)
    {
        int element = a[r][c];
        if (element == target)
        {
            status = true;
            break;
        }
        else if (element > target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    if (status)
    {
        cout << "Target element is there";
    }
    else
    {
        cout << "Target element is not there";
    }
    return 0;
}
