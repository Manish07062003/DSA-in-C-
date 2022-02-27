#include <iostream>
using namespace std;
void sumOfTwoArrays(int *a, int size1, int *b, int size2, int *ans)
{
    int maxsize = size1;
    if (size2 > maxsize)
    {
        maxsize = size2;
    }
    int i = size1 - 1, j = size2 - 1, k = maxsize, carry = 0;
    while (i >= 0 && j >= 0)
    {
        int sum = a[i--] + b[j--] + carry;
        if (sum >= 10)
        {
            sum = sum % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        ans[k--] = sum;
    }
    if (carry)
    {
        ans[0] = carry;
    }
    while (i >= 0)
    {
        ans[k--] = a[i--] + carry;
        carry = 0;
    }
    while (j >= 0)
    {
        ans[k--] = a[j--] + carry;
        carry = 0;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int size1;
    cin >> size1;
    int *input1 = new int[size1];

    for (int i = 0; i < size1; ++i)
    {
        cin >> input1[i];
    }

    int size2;
    cin >> size2;

    int *input2 = new int[size2];

    for (int i = 0; i < size2; ++i)
    {
        cin >> input2[i];
    }

    int outsize = 1 + max(size1, size2);

    int *output = new int[outsize];

    sumOfTwoArrays(input1, size1, input2, size2, output);

    for (int i = 0; i < outsize; ++i)
    {
        cout << output[i] << " ";
    }

    delete[] input1;
    delete[] input2;
    delete[] output;
    cout << endl;
    return 0;
}