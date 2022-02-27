#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
void reverse(char input[], int i, int j)
{
    while (i < j)
    {
        std::swap(input[i++], input[j--]);
    }
}
void reverseStringWordWise(char input[])
{
    int i = 0, previousSpaceIndex = -1;
    while (input[i] != '\0')
    {
        if (input[i] == ' ')
        {
            reverse(input, previousSpaceIndex + 1, i - 1);
            previousSpaceIndex = i;
        }
        i++;
    }
    reverse(input, previousSpaceIndex + 1, i - 1);
    reverse(input, 0, i - 1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char input[100];
    cin.getline(input, 100);
    reverseStringWordWise(input);
    for (int i = 0; input[i] != '\0'; i++)
    {
        cout << input[i];
    }
}
