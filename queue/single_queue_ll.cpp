#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;

    if (front == NULL) {
        front = rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow" << endl;
        return;
    }

    Node* temp = front;
    front = front->next;
    delete temp;

    if (front == NULL)
        rear = NULL;
}

void display() {
    Node* temp = front;

    if (front == NULL) {
        cout << "Queue is empty";
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Queue: ";
    display();

    dequeue();

    cout << "\nAfter deletion: ";
    display();

    return 0;
}