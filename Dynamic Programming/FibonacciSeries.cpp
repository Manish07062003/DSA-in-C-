#include <iostream>
#include <cmath>
using namespace std;
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
int fib_using_memorisation_helper(int n, int *ans)
{
    if (n <= 1)
    {
        return n;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int a = fib_using_memorisation_helper(n - 1, ans);
    int b = fib_using_memorisation_helper(n - 2, ans);
    ans[n] = a + b;
    return ans[n];
}
int fib_using_memorisation(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return fib_using_memorisation_helper(n, ans);
}
int fib_using_iteration(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cout << fib_using_memorisation(20) << endl;
    cout << fib_using_iteration(20) << endl;
    // cout << fib(20000) << endl;
}