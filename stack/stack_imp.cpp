#include <iostream>
using namespace std;
struct node{
    int data;
    node*next;
};
struct node*head;

void push(){
    int n;
    cin>>n;
    node*temp=new node();
    temp->data=n;
    if(head==NULL){
        temp->next=head;
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
}
int pop(){
    if(head==NULL){
        cout<<"Underflow"<<endl;}
        else{
            int x=head->data;
            node*temp=head;
            head=head->next;
            delete temp;
            return x;
        }
    }

    void display(){
        node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    } 
    int main(){
        head=NULL;
        int choice;
        while(1){
            cout<<"1.push 2.pop 3.display 4.exit"<<endl;
            cin>>choice;
            switch(choice){
                case 1: push();
                break;
                case 2: pop();
                break;
                case 3: display();
                break;
                case 4: exit(0);
                default: cout<<"Invalid choice"<<endl;
            }
        }
    }
