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

Node *insertIntoBST(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    if (root->data < val)
        root->right = insertIntoBST(root->right, val);
    if (val < root->data)
        root->left = insertIntoBST(root->left, val);
    return root;
}

Node *buildBST(vector<int> arr)
{
    Node *root = NULL;
    for (int val : arr)
    {
        root = insertIntoBST(root, val);
    }

    return root;
}

void inorder(vector<int> &arr, Node *root)
{
    if (root == NULL)
        return;

    inorder(arr, root->left);
    arr.push_back(root->data);
    inorder(arr, root->right);
}

Node *merge(Node *root1, Node *root2)
{
    vector<int> arr;
    vector<int> arr1;
    vector<int> arr2;
    inorder(arr1, root1);
    inorder(arr2, root2);

    int i = 0;
    int j = 0;
    int n1 = arr1.size();
    int n2 = arr2.size();

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            arr.push_back(arr1[i++]);
        else
            arr.push_back(arr2[j++]);
    }

    while (i < n1)
        arr.push_back(arr1[i++]);
    while (j < n2)
        arr.push_back(arr2[j++]);

    Node *root = buildBST(arr);
    return root;
}

void inorderTraverse(Node *root)
{
    if (root == NULL)
        return;
    inorderTraverse(root->left);
    cout << root->data << " ";
    inorderTraverse(root->right);
}

int main()
{
    vector<int> arr1 = {9, 3, 5, 1};
    vector<int> arr2 = {0, 7, 2, 4};

    Node *root1 = buildBST(arr1);
    Node *root2 = buildBST(arr2);

    cout << "First Binary Tree:" << endl;
    inorderTraverse(root1);
    cout << endl;
    cout << "Second Binary Tree:" << endl;
    inorderTraverse(root2);
    cout << endl;

    Node *mergedNode = merge(root1, root2);
    cout << "Merged Binary Tree:" << endl;
    inorderTraverse(mergedNode);
    cout << endl;
}