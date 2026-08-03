#include <iostream>
using namespace std;
class CircularQueue{
    int front,rear,size;
    int *arr;
    public:
    CircularQueue(int s){
        front=rear=-1;
        size=s;
        arr=new int[s];
    }
    void enqueue(int x){
        if((front==0 && rear==size-1) || (front==rear+1)){
            cout<<"Overflow"<<endl;
            return;
        }
        else if(front==-1){
            front=rear=0;
        }
        else if(rear==size-1){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=x;
    }

    void dequeue(){
        if(front==-1){
            cout<<"Underflow"<<endl;
        }
        else{
            int x=arr[front];
            if(front==rear){
                front=rear=-1;
            }
            else if(front==size-1)
                front=0;
            else
                front++;
            cout<<"Dequeued element: "<<x<<endl;
        }
    }
    void display(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            int i=front;
            while(i!=rear){
                cout<<arr[i]<<" ";
                i=(i+1)%size;
            }
            cout<<arr[rear]<<endl;
        }
    }
};
    int main(){
        int size;
        cout<<"Enter size of circular queue: ";
        cin>>size;
        CircularQueue q(size);
        int choice,x;
        while(1){
            cout<<"1.enqueue 2.dequeue 3.display 4.exit"<<endl;
            cin>>choice;
            switch(choice){
                case 1: cout<<"Enter element to enqueue: ";
                        cin>>x;
                        q.enqueue(x);
                        break;
                case 2: q.dequeue();
                        break;
                case 3: q.display();
                        break;
                case 4: exit(0);
                default: cout<<"Invalid choice"<<endl;
            }
        }
    }