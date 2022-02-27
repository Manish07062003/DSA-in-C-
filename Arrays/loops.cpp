#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    cout << "FOR LOOP\n";
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << sum << endl
         << endl;
    int fact = 1;
    cout << "WHILE LOOP\n";
    int j = 1;
    while (j <= n)
    {
        fact *= j;
        j++;
    }
    cout << fact << endl
         << endl;
    cout << "DO WHILE LOOP\n";
    do
    {
        cout << n << endl;
        cin >> n;
    } while (n > 0);
}