#include <iostream>
#include <cmath>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int size;
    cin >> size;
    int input[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }
    int cnt0 = 0, cnt1;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == 0)
        {
            cnt0++;
        }
    }
    cnt1 = size - cnt0;
    for (int i = 0; i < size; i++)
    {
        if (i < cnt0)
        {
            input[i] = 0;
        }
        else
        {
            input[i] = 1;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
}