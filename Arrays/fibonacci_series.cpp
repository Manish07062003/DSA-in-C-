#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

void fibonacci(int n){
    int f = 0, s = 1, t, i = 1;
    while (i <= n)
    {
        cout << f<<" ";
        t = f + s;
        f = s;
        s = t;
        i++;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    fibonacci(n);
    return 0;
}
