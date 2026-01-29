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

bool searchBst(Node *root, int val)
{
    if (root == NULL)
        return false;

    if (root->data == val)
        return true;

    if (root->data < val)
        return searchBst(root->right, val);
    else
        return searchBst(root->left, val);
}

Node *insert(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

Node *buildBst(vector<int> arr)
{
    Node *root = NULL;
    for (int val : arr)
        root = insert(root, val);
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
    vector<int> arr = {90, 23, 1, 43, 42, 9};
    Node *root = buildBst(arr);
    inOrderTraversal(root);
    int k;
    cout << "\nEnter item to search: ";
    cin >> k;
    bool isFound = searchBst(root, k);
    if (isFound)
        cout << "Item found.";
    else
        cout << "Item not found.";
}