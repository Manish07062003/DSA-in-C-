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
    int temp=n;
    int sum = 0, digit, p = 10;
    while (n > 0)
    {
        digit = n % p;
        sum += pow(digit,3);
        n = n / p;
    }
    if (sum == temp)
    {
        cout << "Is a Armstrong number";
    }
    else
    {
        cout << "Is not a Armstrong number";
    }
    return 0;
}
