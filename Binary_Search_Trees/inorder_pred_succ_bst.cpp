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

Node *getRightMostNodeOfLeftSubtree(Node *root)
{
    while (root != NULL)
        root = root->right;
    return root;
}

Node *getLeftMostNodeOfRightSubtree(Node *root)
{
    while (root != NULL)
        root = root->left;
    return root;
}

vector<int> getInorderSuccessorAndPredecessor(Node *root, int key)
{
    Node *curr = root;
    Node *pred = NULL;
    Node *succ = NULL;
    while (curr != NULL)
    {
        if (key < curr->data)
        {
            succ = curr;
            curr = curr->left;
        }
        else if (curr->data < key)
        {
            pred = curr;
            curr = curr->right;
        }
        else
        {
            if (curr->left != NULL)
            {
                pred = getRightMostNodeOfLeftSubtree(curr);
            }
            if (curr->right != NULL)
            {
                succ = getLeftMostNodeOfRightSubtree(curr);
            }

            break;
        }
    }
    return {pred->data, succ->data};
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key;
    cout << "Enter key: ";
    cin >> key;

    vector<int> ans = getInorderSuccessorAndPredecessor(root, key);
    cout << "Predecessor = " << ans[0] << endl;
    cout << "Successor = " << ans[1] << endl;
}