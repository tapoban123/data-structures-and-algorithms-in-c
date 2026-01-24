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

int diameter = 0;

int calculateDiameter(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHt = calculateDiameter(root->left);
    int rightHt = calculateDiameter(root->right);

    diameter = max(leftHt + rightHt, diameter);
    return max(leftHt, rightHt) + 1;
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

void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main()
{
    vector<int> seq = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(seq);
    inOrderTraversal(root);
    calculateDiameter(root);
    cout << endl;
    cout << "Diameter of tree: " << diameter << endl;
}