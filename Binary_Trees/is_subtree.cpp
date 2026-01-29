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

bool isIdentical(Node *p, Node *q)
{
    if (q == NULL || q == NULL)
        return p == q;

    return isIdentical(p->left, q->left) && isIdentical(p->right, q->right) && p->data == q->data;
}

bool isSubtree(Node *treeRoot, Node *subTreeRoot)
{
    if (treeRoot == NULL || subTreeRoot == NULL)
        return treeRoot == subTreeRoot;

    if (treeRoot->data == subTreeRoot->data && isIdentical(treeRoot, subTreeRoot))
        return true;

    return isSubtree(treeRoot->left, subTreeRoot) || isSubtree(treeRoot->right, subTreeRoot);
}

int index = -1;
Node *buildTree(vector<int> seq)
{
    index++;
    if (seq[index] == -1)
        return NULL;

    Node *root = new Node(seq[index]);
    root->left = buildTree(seq);
    root->right = buildTree(seq);
    return root;
}

int main()
{
    vector<int> treeSeq = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    vector<int> subTreeSeq = {2, 4, -1, -1, 5, -1, -1};
    Node *treeRoot = buildTree(treeSeq);
    index = -1;
    Node *subTreeRoot = buildTree(subTreeSeq);

    bool isSubtreeVal = isSubtree(treeRoot, subTreeRoot);
    if (isSubtreeVal)
        cout << "True";
    else
        cout << "False";
}