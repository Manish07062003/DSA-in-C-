#include <iostream>
using namespace std;
int binarySearch(int n, int arr[], int key)
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (key < arr[mid])
        {
            r = mid - 1;
        }
        else if (key > arr[mid])
        {
            l = mid + 1;
        }
        else if (key == arr[mid])
        {
            return mid;
        }
    }
    return -1;
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
    int key;
    cin >> key;
    cout << binarySearch(n,arr, key);
}