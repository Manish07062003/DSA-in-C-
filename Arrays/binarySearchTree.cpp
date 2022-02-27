#include <iostream>
using namespace std;
typedef struct Node
{
    int val;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

typedef struct
{
    struct Node *root;
} BST;

Node *insert(Node *current, int d)
{
    if (current == NULL)
    {
        current = (Node *)malloc(sizeof(Node));
        current->val = d;
        current->leftChild = NULL;
        current->rightChild = NULL;
        return current;
    }
    if (d < current->val)
    {
        current->leftChild = insert(current->leftChild, d);
    }
    else
    {
        current->rightChild = insert(current->rightChild, d);
    }
    return current;
}

BST *createBST(int data[], int size)
{

    BST *myTree = (BST *)malloc(sizeof(BST));
    myTree->root = NULL;

    for (int i = 0; i < size; i++)
    {
        myTree->root = insert(myTree->root, data[i]);
    }
    return myTree;
}
void inorderTraversal(Node *current)
{
    if (current == NULL)
        return;

    if (current->leftChild != NULL)
        inorderTraversal(current->leftChild);
    cout << current->val << endl;

    if (current->rightChild != NULL)
        inorderTraversal(current->rightChild);
}
void preorderTraversal(Node *current)
{
    if (current == NULL)
    {
        return;
    }
    cout << current->val << endl;
    if (current->leftChild != NULL)
    {
        preorderTraversal(current->leftChild);
    }
    if (current->rightChild != NULL)
    {
        preorderTraversal(current->rightChild);
    }
}
void postorderTraversal(Node *current)
{
    if (current == NULL)
    {
        return;
    }
    if (current->leftChild != NULL)
    {
        postorderTraversal(current->leftChild);
    }
    if (current->rightChild != NULL)
    {
        postorderTraversal(current->rightChild);
    }
    cout << current->val << endl;
}
bool findInBSTHelper(Node *current, int key)
{
    if (current == NULL)
    {
        return false;
    }
    if (current->val == key)
    {
        return true;
    }
    else if (key < current->val)
    {
        current = current->leftChild;
    }
    else
    {
        current = current->rightChild;
    }
    return findInBSTHelper(current, key);
}
bool findInBST(BST *mytree, int key)
{
    return findInBSTHelper(mytree->root, key);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int data[] = {1, 2, 3, 4};
    int size = 4;
    BST *myTree = createBST(data, size);

    cout << "INORDER TRAVERSAL" << endl;
    inorderTraversal(myTree->root);
    cout << endl
         << "PRE TRAVERSAL" << endl;
    preorderTraversal(myTree->root);
    cout << endl
         << "POST TRAVERSAL" << endl;
    postorderTraversal(myTree->root);
    cout << endl
         << "Finding a value in binary tree" << endl;
    cout << findInBST(myTree, 1);
    return 0;
}