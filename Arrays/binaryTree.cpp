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
} BTree;

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
    int guess = rand() % 2;
    if (guess == 0)
    {
        current->leftChild = insert(current->leftChild, d);
    }
    else
    {
        current->rightChild = insert(current->rightChild, d);
    }
    return current;
}

BTree *createTree(int data[], int size)
{

    BTree *myTree = (BTree *)malloc(sizeof(BTree));
    myTree->root = NULL;

    for (int i = 0; i < size; i++)
    {
        myTree->root = insert(myTree->root, data[i]);
    }
    return myTree;
}
int getHeightHelper(Node *current)
{
    if (current == NULL)
    {
        return -1;
    }
    int lheight = getHeightHelper(current->leftChild);
    int rheight = getHeightHelper(current->rightChild);
    return 1 + max(lheight, rheight);
}
int getHeight(BTree *mytree)
{
    return getHeightHelper(mytree->root);
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
bool findInBTHelper(Node *current, int key)
{
    if (current == NULL)
    {
        return false;
    }
    if (current->val == key)
    {
        return true;
    }
    return findInBTHelper(current->leftChild, key) || findInBTHelper(current->rightChild, key);
}
bool findInBT(BTree *mytree, int key)
{
    return findInBTHelper(mytree->root, key);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = 8;
    BTree *myTree = createTree(data, size);

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
    cout << findInBT(myTree, 3);
    cout << endl
         << endl
    << "Height of the binary tree is " << endl;
    cout << getHeight(myTree);
    return 0;
}