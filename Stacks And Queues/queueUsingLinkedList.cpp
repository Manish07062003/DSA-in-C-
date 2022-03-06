#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class Queue
{
    // Define the data members
    Node *head;
    Node *tail;
    int size;

public:
    Queue()
    {
        // Implement the Constructor
        head = NULL;
        tail = NULL;
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function
        return size == 0;
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        size++;
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (head == NULL)
        {
            return -1;
        }
        int ans = head->data;
        Node *temp = head;
        head = head->next;
        size--;
        delete temp;
        return ans;
    }

    int front()
    {
        // Implement the front() function
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Queue q;
    q.enqueue(00);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(90);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.getSize() << endl;

    return 0;
}
