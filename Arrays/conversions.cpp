#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int anybaseTodecimal(int n, int base)
{
    int digit, pow = 1, sum = 0;
    while (n > 0)
    {
        digit = n % 10;
        sum += digit * pow;
        pow *= base;
        n /= 10;
    }
    return sum;
}
int hexadecimalTodecimal(string n)
{
    int sum = 0, x = 1;
    int size = n.size();
    for (int i = size - 1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            sum += (n[i] - '0') * x;
        }
        else if (n[i] >= 'A' && n[i] <= 'F')
        {
            sum += (n[i] - 'A' + 10) * x;
        }
        x *= 16;
    }
    return sum;
}

int decimalTobinary(int n, int base)
{
    int sum = 0, digit, p = 1;
    while (n > 0)
    {
        digit = n % base;
        sum += digit * p;
        n /= base;
        p *= 10;
    }
    return sum;
}
string reversestr(string sum)
{
    string temp = "";
    int s = sum.size();
    for (int i = s - 1; i >= 0; i--)
    {
        char c = sum[i];
        temp.push_back(c);
    }
    return temp;
}
string decimalTohexadecimal(int n)
{
    string sum = "";
    int x = 1, digit;
    while (n > 0)
    {
        digit = n % 16;
        if (digit <= 9)
        {
            sum += to_string(digit);
        }
        else
        {
            char c = 'A' + digit - 10;
            sum.push_back(c);
        }
        n /= 16;
    }
    string temp = reversestr(sum);
    return temp;
}
int reverse(int n)
{
    int rev = 0, digit;
    while (n > 0)
    {
        digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }
    return rev;
}
int addTwoBinaryNums(int a, int b)
{
    int sum = 0, carry = 0;
    while (a > 0 && b > 0)
    {
        if (a % 2 == 0 && b % 2 == 0)
        {
            sum = sum * 10 + carry;
            carry = 0;
        }
        else if (a % 2 == 0 && b % 2 == 1 || a % 2 == 1 && b % 2 == 0)
        {
            if (carry == 1)
            {
                sum = sum * 10 + 0;
                carry = 1;
            }
            else
            {
                sum = sum * 10 + 1;
                carry = 0;
            }
        }
        else
        {
            sum = sum * 10 + carry;
            carry = 1;
        }
        a /= 10;
        b /= 10;
    }
    while (a > 0)
    {
        if (carry == 1)
        {
            if (a % 2 == 1)
            {
                sum = sum * 10 + 0;
                carry = 1;
            }
            else
            {
                sum = sum * 10 + 1;
                carry = 0;
            }
        }
        else
        {
            sum = sum * 10 + (a % 2);
        }
        a /= 10;
    }
    while (b > 0)
    {
        if (carry == 1)
        {
            if (b % 2 == 1)
            {
                sum = sum * 10 + 0;
                carry = 1;
            }
            else
            {
                sum = sum * 10 + 1;
                carry = 0;
            }
        }
        else
        {
            sum = sum * 10 + (b % 2);
        }
        b /= 10;
    }
    if (carry == 1)
    {
        sum = sum * 10 + 1;
    }
    sum = reverse(sum);
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // int n, b;
    // cin >> n >> b;
    // cout << decimalTobinary(n, b);
    // int n;
    // cin >> n;
    // cout << decimalTohexadecimal(n);
    int a, b;
    cin >> a >> b;
    cout << anybaseTodecimal(a, 2) << "+" << anybaseTodecimal(b, 2) << "=" << anybaseTodecimal(addTwoBinaryNums(a, b), 2);
    return 0;
}
