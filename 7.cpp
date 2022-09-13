// /*
// -----MY INPUT FORMATE-----

// */

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

// void printTree(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     cout << root->data << " ";
//     printTree(root->leftChild);
//     printTree(root->rightChild);
// }

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

// // all leaf nodes replaced by 0
// void replaceLeafByZero(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     if (root->leftChild == NULL && root->rightChild == NULL)
//     {
//         root->data = 0;
//     }
//     replaceLeafByZero(root->leftChild);
//     replaceLeafByZero(root->rightChild);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     Node *root = createTree(n);
//     replaceLeafByZero(root);

//     cout << "After replacing leaf nodes by 0: ";
//     printTree(root);
//     return 0;
// }
