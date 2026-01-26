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
    if (p == NULL || q == NULL)
        return p == q;

    return isIdentical(p->left, q->left) && isIdentical(p->right, q->right) && p->data == q->data;
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
    vector<int> seq1 = {1, 2, -1, -1, 3, -1, -1};
    vector<int> seq2 = {1, 2, -1, -1, 3, -1, -1};
    Node *root1 = buildTree(seq1);
    index = -1;
    Node *root2 = buildTree(seq2);
    bool isSame = isIdentical(root1, root2);
    if (isSame)
        cout << "The trees are identical.";
    if (!isSame)
        cout << "The trees are NOT identical.";
}