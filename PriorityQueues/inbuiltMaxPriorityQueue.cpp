#include <iostream>
#include <queue>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    priority_queue<int> pq;
    pq.push(10);
    pq.push(1);
    pq.push(20);
    pq.push(0);
    pq.push(30);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    cout << pq.empty() << endl;
    cout << pq.size() << endl;
}