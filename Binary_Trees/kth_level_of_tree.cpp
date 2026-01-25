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

void kthLevel(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    kthLevel(root->left, k - 1);
    kthLevel(root->right, k - 1);
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
    vector<int> seq = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int k = 2;
    Node *root = buildTree(seq);
    kthLevel(root, k);
}