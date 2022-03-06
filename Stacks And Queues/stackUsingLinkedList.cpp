#include <iostream>
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

class Stack
{
    // Define the data members
    Node *head;
    int size;

public:
    Stack()
    {
        // Implement the Constructor
        head = NULL;
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
        return (head == NULL);
    }

    void push(int element)
    {
        // Implement the push() function
        Node *newNode = new Node(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    int pop()
    {
        // Implement the pop() function
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

    int top()
    {
        // Implement the top() function
        if (size == 0)
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
    Stack s;
    s.push(10);
    s.push(20);
    s.push(40);
    s.push(103);
    s.push(50);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    return 0;
}