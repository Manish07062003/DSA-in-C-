#include <iostream>
using namespace std;
#include <climits>
int solve(string s, string v)
{
    // Write your code here
    if (s.length() == 0)
        return 1005;

    if (v.length() == 0)
        return 1;

    int i;
    for (i = 0; i < v.length(); i++)
    {

        if (v[i] == s[0])
            break;
    }

    if (i == v.length())
        return 1;

    int x = solve(s.substr(1), v);
    int y = 1 + solve(s.substr(1), v.substr(i + 1));
    return min(x, y);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s, t;
    cin >> s >> t;
    cout << solve(s, t);
}