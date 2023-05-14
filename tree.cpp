#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    void postOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        stack<Node *> a, b;
        a.push(root);
        Node *prev = nullptr;
        while (!a.empty())
        {
            Node *curr1 = a.top();
            a.pop();
            b.push(curr1);
            if (curr1->left)
            {
                a.push(curr1->left);
            }
            if (curr1->right)
            {
                a.push(curr1->right);
            }
        }
        while (!b.empty())
        {
            Node *curr2 = b.top();
            b.pop();
            cout << curr2->data << " ";
        }
    }

    void postorderTraversal(Node *root)
    {
        if (!root)
        {
            return;
        }
        stack<Node *> s;
        Node *prev = nullptr;
        while (!s.empty() || root)
        {
            if (root)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                Node *curr = s.top();
                if (curr->right && prev != curr->right)
                {
                    root = curr->right;
                }
                else
                {
                    prev = s.top();
                    s.pop();
                    cout << prev->data << " ";
                }
            }
        }
    }

    void inorderTraversal(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        stack<Node *> s;
        Node *tmp = root;
        while (!s.empty() || tmp != nullptr)
        {
            while (tmp != nullptr)
            {
                s.push(tmp);
                tmp = tmp->left;
            }

            tmp = s.top();
            s.pop();
            cout << tmp->data << " ";
            tmp = tmp->right;
        }
    }

    void preorderTraversal(Node *root)
    {
        stack<Node *> s;
        s.push(root);
        while (!s.empty())
        {
            Node *curr = s.top();
            s.pop();
            if (curr)
            {
                cout << curr->data << " ";
                s.push(curr->right);
                s.push(curr->left);
            }
        }
    }

};

int main()
{
    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.postOrder(root);

    return 0;
}
