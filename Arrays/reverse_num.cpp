#include <iostream>
#include <fstream>
#include <string>
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
    int revNum = 0, digit, p = 10;
    while (n > 0)
    {
        digit = n % p;
        revNum = revNum * 10 + digit;
        n = n / p;
    }
    cout << revNum;
    return 0;
}