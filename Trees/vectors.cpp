#include <iostream>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // static allocation
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // dont use v[] for inserting elements
    // v[0]=100;

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;

    cout << v.at(3) << endl;

    cout << v.size() << endl;

    // pops the last element
    v.pop_back();

    cout << v.size() << endl;

    // prints error out of range
    // cout << v.at(5) << endl;

    // dynamic allocation;
    // vector<int> *v1 = new vector<int>;
}
