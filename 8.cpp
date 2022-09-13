/*
-----MY INPUT FORMATE-----

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

void average_level(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    float sum = 0;
    int count = 0;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            float avg = sum / count;
            cout << avg << " ";
            sum = 0;
            count = 0;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            sum += temp->data;
            count++;
            if (temp->leftChild != NULL)
            {
                q.push(temp->leftChild);
            }
            if (temp->rightChild != NULL)
            {
                q.push(temp->rightChild);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    Node *root = createTree(n);

    cout << "Average of each level is: ";
    average_level(root);

    return 0;
}
