#include <iostream>
#include <vector>
#include <map>
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

void topViewOfTree(Node *root)
{
    queue<pair<Node *, int>> q; // (Node, horizontalDistance)
    map<int, int> m;

    if (root == NULL)
        return;

    q.push({root, 0});
    while (q.size() != 0)
    {
        Node *curr = q.front().first;
        int currHd = q.front().second;
        q.pop();

        if (m.find(currHd) == m.end())
        {
            m[currHd] = curr->data;
        }
        if (curr->left != NULL)
            q.push({curr->left, currHd - 1});
        if (curr->right != NULL)
            q.push({curr->right, currHd + 1});
    }

    for (auto it : m)
    {
        cout << it.second << " ";
    }
}

int main()
{
    vector<int> seq = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(seq);
    topViewOfTree(root);
}