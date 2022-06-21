#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> RemoveDuplicates(int arr[], int n)
{
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i = 0; i < n; i++)
    {
        if (seen.count(arr[i]) > 0)
        {
            continue;
        }
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = RemoveDuplicates(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}