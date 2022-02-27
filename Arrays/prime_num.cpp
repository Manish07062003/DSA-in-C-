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
    bool status = 0;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << "Not a Prime number";
            status = 1;
            break;
        }
    }
    if (status == 0)
    {
        cout << "Is a Prime number";
    }
    return 0;
}