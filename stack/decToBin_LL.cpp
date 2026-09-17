#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == NULL)
            return -1;

        int x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;

        return x;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    int n;

    cout << "Enter decimal number: ";
    cin >> n;

    Stack s;

    if (n == 0) {
        cout << "Binary = 0";
        return 0;
    }

    while (n > 0) {
        int remainder = n % 2;
        s.push(remainder);
        n = n / 2;
    }

    cout << "Binary = ";

    while (!s.isEmpty()) {
        cout << s.pop();
    }

    return 0;
}