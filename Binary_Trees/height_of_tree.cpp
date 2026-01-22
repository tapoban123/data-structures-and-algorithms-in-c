// Algorithms of height of tree and count number of nodes in a tree are implemented here

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

Node *buildTree(vector<int> preOrderSeq)
{
    static int index = -1;
    index++;

    if (preOrderSeq[index] == -1)
        return NULL;

    Node *root = new Node(preOrderSeq[index]);
    root->left = buildTree(preOrderSeq);
    root->right = buildTree(preOrderSeq);

    return root;
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int heightOfTree(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHt = heightOfTree(root->left);
    int rightHt = heightOfTree(root->right);
    return max(leftHt, rightHt) + 1;
}

int countNumberOfNodesInTree(Node *root)
{
    if (root == NULL)
        return 0;

    int leftCount = countNumberOfNodesInTree(root->left);
    int rightCount = countNumberOfNodesInTree(root->right);

    return leftCount + rightCount + 1;
}

int sumOfNodes(Node *root)
{
    if (root == NULL)
        return 0;

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return leftSum + rightSum + root->data;
}

int main()
{
    vector<int> preOrderSeq = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preOrderSeq);

    postOrderTraversal(root);

    cout << "\n";
    int height = heightOfTree(root);
    int nodesCount = countNumberOfNodesInTree(root);
    int nodesSum = sumOfNodes(root);

    cout << "Height of Tree: " << height << endl;
    cout << "Total count of nodes: " << nodesCount << endl;
    cout << "Sum of nodes: " << nodesSum << endl;
}