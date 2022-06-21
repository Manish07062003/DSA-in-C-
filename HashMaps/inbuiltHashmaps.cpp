#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // unordered_map<key_Type, value_Type>
    unordered_map<string, int> ourMap;

    // insert
    pair<string, int> p("abc", 1);
    ourMap.insert(p);
    ourMap["def"] = 2;

    //find or access
    cout << ourMap["abc"] << endl;
    cout << ourMap.at("def") << endl;

    // erase
    ourMap.erase("abc");

    // check presence
    if (ourMap.count("abc") > 0)
    {
        cout << "abc is present" << endl;
    }
    else
    {
        cout << "abc is not present" << endl;
    }

    //size
    cout << ourMap.size() << endl;
}