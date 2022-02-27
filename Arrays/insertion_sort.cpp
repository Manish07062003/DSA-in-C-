#include <iostream>
using namespace std;
int *insertionSort(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        int crr = a[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (crr < a[j])
            {
                a[j + 1] = a[j];
                a[j] = crr;
            }
        }
    }
    return a;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int *sort = insertionSort(n, arr);
    for (int i = 0; i < n; i++)
    {
        cout << sort[i] << " ";
    }
}