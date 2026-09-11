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

int countNodes(node *root){
    if(root==NULL)
    return 0;
     
    return 1+countNodes(root->left)+countNodes(root->right);
}

int main(){
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);

    cout<<"The count of nodes="<<countNodes(root);
}