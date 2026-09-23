#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> levelOrder(node* root)
{
    vector<vector<int>> result;

    if(root == NULL)
        return result;

    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for(int i = 0; i < size; i++)
        {
            node* current = q.front();
            q.pop();

            level.push_back(current->data);

            if(current->left != NULL)
                q.push(current->left);

            if(current->right != NULL)
                q.push(current->right);
        }

        result.push_back(level);
    }

    return result;
}

int main()
{
    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<vector<int>> result = levelOrder(root);

    for(const auto& level : result)
    {
        for(int val : level)
        {
            cout << val << " ";
        }

        cout << endl;
    }

    return 0;
}