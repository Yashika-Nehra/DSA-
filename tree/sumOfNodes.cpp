#include <iostream>
using namespace std;

struct node{
    int val;
    node *left;
    node *right;

    node(int data){
        val=data;
        left=right=NULL;
    }
};

int sumOfNodes(node *root){
    if(root==NULL)
    return 0;

    return root->val+sumOfNodes(root->left)+sumOfNodes(root->right);
}

int main(){
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->right=new node(6);

    cout<<"The sum of nodes="<<sumOfNodes(root);
}