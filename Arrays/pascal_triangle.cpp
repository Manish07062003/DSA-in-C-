#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int fact(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, nCr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            nCr = fact(i) / (fact(i - j) * fact(j));
            cout << nCr
                 << " ";
        }
        cout << endl;
    }
    return 0;
}