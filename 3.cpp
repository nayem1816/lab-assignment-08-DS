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

void level_order_reverse(Node *root)
{
    queue<Node *> q;
    stack<Node *> s;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        s.push(temp);
        if (temp->rightChild != NULL)
        {
            q.push(temp->rightChild);
        }
        if (temp->leftChild != NULL)
        {
            q.push(temp->leftChild);
        }
    }
    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
}

int main()
{
    int n;
    cin >> n;

    Node *root = createTree(n);

    cout << "Level order reverse print: ";
    level_order_reverse(root);

    return 0;
}
