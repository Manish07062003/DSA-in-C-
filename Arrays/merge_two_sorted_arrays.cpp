#include <iostream>
#include <cmath>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int size1, size2;
    cin >> size1;
    int a[size1];
    for (int i = 0; i < size1; i++)
    {
        cin >> a[i];
    }
    cin >> size2;
    int b[size2];
    for (int i = 0; i < size2; i++)
    {
        cin >> b[i];
    }
    int ans[size1 + size2];
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (a[i] <= b[j])
        {
            ans[k++] = a[i++];
        }
        else
        {
            ans[k++] = b[j++];
        }
    }
    while (i < size1)
    {
        ans[k++] = a[i++];
    }
    while (j < size2)
    {
        ans[k++] = b[j++];
    }
    for (int i = 0; i < k; i++)
    {
        cout << ans[i] << " ";
    }
}