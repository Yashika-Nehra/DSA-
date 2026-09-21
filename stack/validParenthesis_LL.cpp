#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char x) {
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

    void push(char x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == NULL)
            return '\0';

        char x = top->data;
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
    char exp[100];

    cout << "Enter expression: ";
    cin.getline(exp, 100);

    Stack s;

    for (int i = 0; exp[i] != '\0'; i++) {

        if (exp[i] == '(') {
            s.push(exp[i]);
        }

        else if (exp[i] == ')') {

            if (s.isEmpty()) {
                cout << "Invalid Expression";
                return 0;
            }

            s.pop();
        }
    }

    if (s.isEmpty())
        cout << "Valid Expression";
    else
        cout << "Invalid Expression";

    return 0;
}