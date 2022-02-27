

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i0 = 0, i2 = n - 1, i = 0;
    while (i <= i2)
    {
        if (a[i] == 0)
        {
            int temp = a[i];
            a[i] = a[i0];
            a[i0] = temp;
            i0++;
            i++;
        }
        else if (a[i] == 2)
        {
            int temp = a[i];
            a[i] = a[i2];
            a[i2] = temp;
            i2--;
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}