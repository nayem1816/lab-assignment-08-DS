/*
-----MY INPUT FORMATE-----

First TREE Input
3
1 2 3
2 -1 -1
3 -1 -1
3
1 2 3
2 -1 -1
3 -1 -1

Second TREE Input
2
1 2 -1
2 -1 -1
2
1 -1 2
2 -1 -1

Third TREE Input
3
1 2 1
2 -1 -1
1 -1 -1
3
1 1 2
1 -1 -1
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

bool isSame(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }
    return isSame(root1->leftChild, root2->leftChild) && isSame(root1->rightChild, root2->rightChild);
}

int main()
{
    int n1;
    cout << "Enter the number of nodes: ";
    cin >> n1;
    Node *root1 = createTree(n1);

    int n2;
    cout << "Enter the number of nodes: ";
    cin >> n2;
    Node *root2 = createTree(n2);

    if (isSame(root1, root2))
    {
        cout << "Both trees are same";
    }
    else
    {
        cout << "Both trees are not same";
    }

    return 0;
}
