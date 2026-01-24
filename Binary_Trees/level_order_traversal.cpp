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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    if (root == NULL)
        return;

    q.push(root);
    q.push(NULL); // Inserting NULL to detect new lines for each level 
    while (q.size() != 0)
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
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
        cout << curr->data << " ";

        if (curr->left != NULL)
            q.push(curr->left);

        if (curr->right != NULL)
            q.push(curr->right);
    }
    cout << endl;
}

int main()
{
    vector<int> seq = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(seq);
    levelOrderTraversal(root);
}