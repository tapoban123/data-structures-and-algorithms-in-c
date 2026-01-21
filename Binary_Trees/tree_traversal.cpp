/*
Four Types of Tree traversal:
1. PreOrder traversal -> The left subtree is travelled first.
2. Inorder Traversal -> The root is travelled before the children.
3. PostOrder Traversal -> The root is travelled after it's children are travelled.
4. LevelOrder Traversal -> Each level is travelled individually.

NOTE: The output of each traversal might be different.
*/

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(vector<int> preorderSeq)
{
    static int index = -1;
    index++;

    if (preorderSeq[index] == -1)
        return NULL;

    Node *root = new Node(preorderSeq[index]);
    root->left = buildTree(preorderSeq);
    root->right = buildTree(preorderSeq);

    return root;
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{
    vector<int> preorderSeq = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorderSeq);

    cout << "Running PreOrder Traversal:" << endl;
    preOrderTraversal(root);
}