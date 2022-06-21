#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    unordered_map<string, int> map;
    map["abc"] = 1;
    map["abc1"] = 2;
    map["abc2"] = 3;
    map["abc3"] = 4;
    map["abc4"] = 5;
    map["abc5"] = 6;

    // iterator
    unordered_map<string, int>::iterator it = map.begin();
    while (it != map.end())
    {
        cout << "Key: " << it->first << " Value: " << it->second << endl;
        it++;
    }
    cout << endl;

    // find

    // the find function in unordered maps return an iterator
    unordered_map<string, int>::iterator it2 = map.find("abc");

    // an erase function can delete pair using iterator also
    map.erase(it2);

    // deletes till it2+3 from it2
    map.erase(it2, it2 + 4);

    // in vectors
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    vector<int>::iterator it1 = v.begin();
    cout << "Vector values are: " << endl;
    while (it1 != v.end())
    {
        cout << *it1 << endl;
        it1++;
    }
}