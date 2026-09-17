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
        cout << "Hexadecimal = 0";
        return 0;
    }

    while (n > 0) {
        s.push(n % 16);
        n = n / 16;
    }

    cout << "Hexadecimal = ";

    while (!s.isEmpty()) {
        int x = s.pop();

        if (x < 10)
            cout << x;
        else
            cout << char('A' + x - 10);
    }

    return 0;
}