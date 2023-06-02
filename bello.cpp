#include <bits/stdc++.h>

using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
ii see[2000100];
vector<int>v;
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
    Node *insert(Node *root, int data,int level,int depth)
    {
        //cout<<"**\n";
        if (root == NULL)
        {
            //cout<<"*\n";
            if(see[level].fi==0)
            {
                see[level].fi=data;
                see[level].se=depth;
            }
            else
            {
                if(see[level].se>depth)
                {
                    see[level].fi=data;
                    see[level].se=depth;
                }
            }
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data,level-1,depth+1);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data,level+1,depth+1);
                root->right = cur;
            }

            return root;
        }
    }
};
int main()
{
    Solution p;
    Node *root=NULL;
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        root=p.insert(root,x,1000000,0);
    }
    for(int i=0;i<=2000000;i++)
    {
        if(see[i].fi!=0)
        {
            v.push_back(see[i].fi);
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
/*
8
2 1 6 5 8 4 7 3

6
1 5 3 4 3 5

5
2 6 5 4 1

10
5 3 7 2 4 6 8 1 9 10

*/