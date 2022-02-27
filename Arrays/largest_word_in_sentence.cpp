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
    cin.getline(a, 100); //takes the string (sentence)
    cin.ignore();        //ignore any buffers
    int i = 0, clength = 0, maxlength = INT_MIN, st = 0, maxst = 0;
    while (1)
    {
        if (a[i] == ' ' || a[i] == '\0')
        {
            if (clength > maxlength)
            {
                maxlength = clength;
                maxst = st;
            }
            clength = 0;
            st = i + 1;
        }
        else
        {
            clength++;
        }
        if (a[i] == '\0')
        {
            break;
        }
        i++;
    }
    cout << maxlength<<endl;
    for (int i = 0; i < maxlength; i++)
    {
        cout << a[i + maxst];
    }
    return 0;
}
