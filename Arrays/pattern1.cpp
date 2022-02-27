#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*"
                 << " ";
        }
        for (int j = 1; j <= 2 * n - 2 * i; j++)
        {
            cout << " "
                 << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*"
                 << " ";
        }
        cout << "\n";
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*"
                 << " ";
        }
        for (int j = 1; j <= 2 * n - 2 * i; j++)
        {
            cout << " "
                 << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*"
                 << " ";
        }
        cout << "\n";
    }
}