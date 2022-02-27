
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, d;
    cin >> n >> d; // rotate number
    int input[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int rotateEle[d], k = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < d)
        {
            rotateEle[i] = input[i];
        }
        else
        {
            input[k++] = input[i];
        }
    }
    for (int i = 0; i < d; i++)
    {
        input[k++] = rotateEle[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
}