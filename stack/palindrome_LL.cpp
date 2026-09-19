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
        char x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }
};

int main() {
    char str[100];

    cout << "Enter string: ";
    cin >> str;

    Stack s;

    int i = 0;

    while (str[i] != '\0') {
        s.push(str[i]);
        i++;
    }

    i = 0;

    while (str[i] != '\0') {
        if (str[i] != s.pop()) {
            cout << "Not Palindrome";
            return 0;
        }

        i++;
    }

    cout << "Palindrome";

    return 0;
}