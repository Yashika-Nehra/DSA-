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

node* insert(node* root, int x)
{
    if(root == NULL)
    {
        return new node(x);
    }

    if(x < root->data)
    {
        root->left = insert(root->left, x);
    }
    else
    {
        root->right = insert(root->right, x);
    }

    return root;
}

node* search(node* root, int x)
{
    if(root == NULL || root->data == x)
    {
        return root;
    }

    if(x < root->data)
    {
        return search(root->left, x);
    }
    else
    {
        return search(root->right, x);
    }
}

void inorder(node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node* root = NULL;
    int n, x, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nEnter element to search: ";
    cin >> key;

    if(search(root, key) != NULL)
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }

    return 0;
}