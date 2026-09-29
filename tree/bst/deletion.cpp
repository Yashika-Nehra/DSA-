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

node* findMin(node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node* deleteNode(node* root, int x)
{
    if(root == NULL)
        return root;

    if(x < root->data)
    {
        root->left = deleteNode(root->left, x);
    }
    else if(x > root->data)
    {
        root->right = deleteNode(root->right, x);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            node* successor = findMin(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }

    return root;
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

    cout << "\nEnter element to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "Inorder after deletion: ";
    inorder(root);

    return 0;
}