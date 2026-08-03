#include <bits/stdc++.h>
using namespace std;
class Queue{
    int front,rear,size;
    int *arr;
public:
    Queue(int s){
        front=rear=-1;
        size=s;
        arr=new int[s];
    }
  void enqueue(int x){
        if(rear==size-1){
            cout<<"Overflow"<<endl;
        }
        else{
            if(front ==-1)
                front=0;
            rear++;
            arr[rear]=x;
        }
    }
    int dequeue(){
        if(front==-1 || front>rear){
            cout<<"Underflow"<<endl;
            return -1;
        }
        else{
            int x=arr[front];
            front++;
            return x;
        }
    }
    void display(){
        if(front==-1 || front>rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        for(int i=front;i<=rear;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){
    int size;
    cout<<"Enter size of queue: ";
    cin>>size;
    Queue q(size);
    int choice,x;
    while(1){
        cout<<"1.enqueue 2.dequeue 3.display 4.exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter element to enqueue: ";
                    cin>>x;
                    q.enqueue(x);
                    break;
            case 2: x=q.dequeue();
                    if(x!=-1)
                        cout<<"Dequeued element: "<<x<<endl;
                    break;
            case 3: q.display();
                    break;
            case 4: exit(0);
            default: cout<<"Invalid choice"<<endl;
        }
    }
}