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
    int n, base;

    cout << "Enter decimal number: ";
    cin >> n;

    cout << "Enter base: ";
    cin >> base;

    if (base < 2 || base > 16) {
        cout << "Base should be between 2 and 16";
        return 0;
    }

    Stack s;

    if (n == 0) {
        cout << "Result = 0";
        return 0;
    }

    while (n > 0) {
        s.push(n % base);
        n = n / base;
    }

    cout << "Result = ";

    while (!s.isEmpty()) {
        int x = s.pop();

        if (x < 10)
            cout << x;
        else
            cout << char('A' + x - 10);
    }

    return 0;
}