/*
-----MY INPUT FORMATE-----

First Input
5
2 2 5
2 -1 -1
5 5 7
5 -1 -1
7 -1 -1

Second Input
3
2 2 2
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

// 2nd minimum element in a binary search tree
int second_minimum(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        return -1;
    }
    int left = root->leftChild->data;
    int right = root->rightChild->data;
    if (left == root->data)
    {
        left = second_minimum(root->leftChild);
    }
    if (right == root->data)
    {
        right = second_minimum(root->rightChild);
    }
    if (left != -1 && right != -1)
    {
        return min(left, right);
    }
    else if (left != -1)
    {
        return left;
    }
    else
    {
        return right;
    }
}

int main()
{
    int n;
    cin >> n;

    Node *root = createTree(n);

    cout << "Second Minimum Value is: " << second_minimum(root) << endl;

    return 0;
}
