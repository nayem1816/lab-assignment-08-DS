/*
-----MY INPUT FORMATE-----

First Input
6
1 1 1
1 1 1
1 -1 -1
1 -1 -1
1 -1 1
1 -1 -1

Second Input
5
2 2 2
2 5 2
5 -1 -1
2 -1 -1
2 -1 -1

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *leftChild;
    Node *rightChild;
    Node(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printTree(root->leftChild);
    printTree(root->rightChild);
}

Node *createTree(int n)
{
    Node *root = new Node(-1);
    if (n == 0)
    {
        return NULL;
    }
    else
    {
        int data;
        cin >> data;
        root->data = data;
        int leftChild, rightChild;
        cin >> leftChild >> rightChild;
        if (leftChild != -1)
        {
            root->leftChild = createTree(leftChild);
        }
        if (rightChild != -1)
        {
            root->rightChild = createTree(rightChild);
        }
        return root;
    }
}

bool is_unival(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->leftChild != NULL && root->leftChild->data != root->data)
    {
        return false;
    }
    if (root->rightChild != NULL && root->rightChild->data != root->data)
    {
        return false;
    }
    if (is_unival(root->leftChild) && is_unival(root->rightChild))
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    Node *root = createTree(n);

    if (is_unival(root))
    {
        cout << "This is an uni-valued tree.";
    }
    else
    {
        cout << "This is not an uni-valued tree.";
    }

    return 0;
}
