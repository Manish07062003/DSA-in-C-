#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char a[100];
    cin >> a;
    int length = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        length++;
    }
    bool check = 1;
    for (int i = 0; i < length; i++)
    {
        if (a[i] != a[length - i - 1])
        {
            check = 0;
            break;
        }
    }
    if (check == true)
    {
        cout << "is palindrome";
    }
    else
    {
        cout << "is not palindrome";
    }
    return 0;
}
