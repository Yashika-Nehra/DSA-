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

int countTwoChildNodes(node *root){
    if(root==NULL)
    return 0;

    int count=0;
    if(root->left!=NULL && root->right!=NULL)
    count=1;

    return count+countTwoChildNodes(root->left)+countTwoChildNodes(root->right);
}

int main(){
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->right=new node(6);

    cout<<"The count of nodes with two children="<<countTwoChildNodes(root);
}