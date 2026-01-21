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
    {
        return NULL;
    }

    Node *root = new Node(preorderSeq[index]);
    root->left = buildTree(preorderSeq);
    root->right = buildTree(preorderSeq);

    return root;
}

int main()
{
    vector<int> preorderSeq = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorderSeq);

    cout << "Root: " << root->data << endl;
    cout << "Left Child: " << root->left->data << endl;
    cout << "Right Child: " << root->right->data << endl;
}