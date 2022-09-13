/*
-----MY INPUT FORMATE-----

7
1 2 7
2 1 3
1 -1 -1
3 -1 -1
7 6 9
6 -1 -1
9 -1 -1


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

Node *invert_tree(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *temp = root->leftChild;
    root->leftChild = root->rightChild;
    root->rightChild = temp;
    invert_tree(root->leftChild);
    invert_tree(root->rightChild);
    return root;
}

int main()
{
    int n;
    cin >> n;

    Node *root = createTree(n);

    cout << "Original Tree: ";
    printTree(root);

    cout << endl;

    Node *res;
    res = invert_tree(root);

    cout << "Inverted Tree: ";
    printTree(res);

    return 0;
}
