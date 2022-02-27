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
    int num;
    int max = INT_MIN;
    if (n == 1 || n == 0)
    {
        cout << INT_MIN;
        return 0;
    }
    int smax = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        if (num > smax)
        {
            if (num < max)
            {
                smax = num;
            }
            else if (num > max)
            {
                smax = max;
                max = num;
            }
        }
    }
    cout << smax;
}