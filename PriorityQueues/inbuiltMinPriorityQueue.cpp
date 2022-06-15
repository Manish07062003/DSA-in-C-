#include <iostream>
#include <queue>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // greater<int> swaps the functionality of maxHeap to minHeap
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(10);
    pq.push(1);
    pq.push(20);
    pq.push(0);
    pq.push(30);
    cout << pq.top() << endl;
    pq.pop();
    pq.pop();
    cout << pq.top() << endl;
    cout << pq.empty() << endl;
    cout << pq.size() << endl;
}