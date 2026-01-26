#include <iostream>
#include <vector>
#include <queue>
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

Node *findLCA(Node *root, Node *p, Node *q)
{
    if (root == NULL)
        return NULL;

    if (root->data == p->data || root->data == q->data)
        return root;

    Node *leftLCA = findLCA(root->left, p, q);
    Node *rightLCA = findLCA(root->right, p, q);

    if (leftLCA && rightLCA)
        return root;
    if (leftLCA != NULL)
        return leftLCA;
    if (rightLCA != NULL)
        return rightLCA;

    return NULL;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    if (root == NULL)
        return;

    q.push(root);
    q.push(NULL);
    while (q.size() != 0)
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
                break;
        }

        cout << front->data << " ";
        if (front->left != NULL)
            q.push(front->left);
        if (front->right != NULL)
            q.push(front->right);
    }
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
    Node *p = new Node(5);
    Node *q = new Node(2);
    Node *root = buildTree(seq);
    levelOrderTraversal(root);
    Node *lca = findLCA(root, p, q);

    cout << "LCA = " << lca->data;
}