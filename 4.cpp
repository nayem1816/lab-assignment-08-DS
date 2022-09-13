// #include <bits/stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *leftChild;
//     Node *rightChild;
//     Node(int value)
//     {
//         data = value;
//         leftChild = NULL;
//         rightChild = NULL;
//     }
// };

// Node *createTree(int n)
// {
//     Node *root = new Node(-1);
//     if (n == 0)
//     {
//         return NULL;
//     }
//     else
//     {
//         int data;
//         cin >> data;
//         root->data = data;
//         int leftChild, rightChild;
//         cin >> leftChild >> rightChild;
//         if (leftChild != -1)
//         {
//             root->leftChild = createTree(leftChild);
//         }
//         if (rightChild != -1)
//         {
//             root->rightChild = createTree(rightChild);
//         }
//         return root;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     Node *root = createTree(n);
//     return 0;
// }