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

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
Node *insert(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    Node *temp = head;
    int positionIndex = 0;
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    while (temp != NULL && positionIndex < i - 1)
    {
        positionIndex++;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}
Node *insertNodeRecursive(Node *head, int i, int data)
{
    if (head == NULL)
    {
        if (i == 0)
        {
            Node *newNode = new Node(data);
            return newNode;
        }
        return head;
    }
    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    head->next = insertNodeRecursive(head->next, i - 1, data);
    return head;
}
Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    if (head == NULL)
    {
        return head;
    }
    if (pos == 0)
    {
        head = head->next;
        return head;
    }
    int position = 0;
    Node *temp = head;
    while (temp != NULL && position < pos - 1)
    {
        position++;
        temp = temp->next;
    }
    if (temp->next != NULL)
    {
        Node *nextNode = temp->next;
        temp->next = nextNode->next;
    }
    return head;
}
Node *deleteNodeRecursive(Node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }
    if (pos == 0)
    {
        return head->next;
    }
    head->next = deleteNodeRecursive(head->next, pos - 1);
    return head;
}
int length(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return 1 + length(head->next);
}
Node *reverseLinkedListRecursive(Node *head)
{
    //Write your code here
    // First Approach
    // time complexity is O(N)

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallerOutput = reverseLinkedListRecursive(head->next);
    Node *tail = head->next;
    head->next = NULL;
    tail->next = head;
    return smallerOutput;

    // Second Approach
    // time complexity is O(N^2)

    // if(head==NULL||head->next==NULL){
    //     return head;
    // }
    // Node* smallerOutput=reverseLinkedListRec(head->next);
    // Node* temp=smallerOutput;
    // while(smallerOutput->next!=NULL){
    //     smallerOutput=smallerOutput->next;
    // }
    // head->next=NULL;
    // smallerOutput->next=head;
    // return temp;
}
Node *reverseLinkedListIterative(Node *head)
{
    // Write your code here
    Node *current = head;
    Node *previous = NULL;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *head = takeInput();
    // head = insert(head, 0, 2);
    // print(head1);
    // cout << length(head) << endl;
    head = deleteNode(head, 5);
    head = reverseLinkedListRec(head);
    print(head);

    // statically
    // Node n1(1);
    // Node *head = &n1;
    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);
    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    // print(head);

    // dynamically
    // Node *n3 = new Node(10);
    // Node *head=n3;
    // Node *n4 = new Node(20);
    // since n4 stores the address of the node we will directly pass n4 to n3->next
    // n3->next = n4;
}