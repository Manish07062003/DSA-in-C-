#include <iostream>
#include <queue>
#include "TreeNodeClass.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Root Data " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNode;
    pendingNode.push(root);
    while (pendingNode.size() != 0)
    {
        TreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        int numChilds;
        cout << "Enter number of childs for " << front->data << endl;
        cin >> numChilds;
        for (int i = 0; i < numChilds; i++)
        {
            int childData;
            cout << "Enter the data of " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter number of childrens of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
void printTreeLevelWise(TreeNode<int> *root)
{
    // Write your code here
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            TreeNode<int> *child = front->children[i];
            if (i == front->children.size() - 1)
            {
                cout << child->data;
            }
            else
            {
                cout << child->data << ",";
            }
            pendingNodes.push(child);
        }
        cout << endl;
    }
}
void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

// Traversals

// preorder
void preorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

// postorder
void postorder(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}

// 1 3 2 3 4 2 5 6 0 0 0 0

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    TreeNode<int> *root = takeInputLevelWise();
    // printTreeLevelWise(root);
    preorder(root);
    cout << endl;
    postorder(root);

    // destructor of the TreeNode class will be called
    delete root;
}