/*
-----MY INPUT FORMATE-----

First TREE Input
5
3 9 20
9 -1 -1
20 15 7
15 -1 -1
7 -1 -1

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

void zigzag_order(Node *root)
{
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            cout << temp->data << " ";
            if (temp->leftChild != NULL)
            {
                s2.push(temp->leftChild);
            }
            if (temp->rightChild != NULL)
            {
                s2.push(temp->rightChild);
            }
        }
        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            cout << temp->data << " ";
            if (temp->rightChild != NULL)
            {
                s1.push(temp->rightChild);
            }
            if (temp->leftChild != NULL)
            {
                s1.push(temp->leftChild);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    Node *root = createTree(n);

    cout << "ZigZag Order Traversal: ";
    zigzag_order(root);

    return 0;
}
