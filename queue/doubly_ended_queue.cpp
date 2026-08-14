#include <iostream>
using namespace std;

class DoublyEndedQueue {
    int front, rear, size;
    int *arr;

public:
    DoublyEndedQueue(int s) {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enqueueFront(int x) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
            cout << "Overflow" << endl;
            return;
        }
        else if (front == -1) {
            front = rear = 0;
        }
        else if (front == 0) {
            front = size - 1;
        }
        else {
            front--;
        }

        arr[front] = x;
    }

    void dequeueFront() {
        if (front == -1) {
            cout << "Underflow" << endl;
            return;
        }

        int x = arr[front];

        if (front == rear) {
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }

        cout << "Dequeued element from front: " << x << endl;
    }

    void enqueueRear(int x) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
            cout << "Overflow" << endl;
            return;
        }
        else if (front == -1) {
            front = rear = 0;
        }
        else if (rear == size - 1) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = x;
    }

    void dequeueRear() {
        if (front == -1) {
            cout << "Underflow" << endl;
            return;
        }

        int x = arr[rear];

        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }

        cout << "Dequeued element from rear: " << x << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
        }
        else {
            int i = front;

            while (i != rear) {
                cout << arr[i] << " ";
                i = (i + 1) % size;
            }

            cout << arr[rear] << endl;
        }
    }
};

int main() {
    int size;

    cout << "Enter the size of the queue: ";
    cin >> size;

    DoublyEndedQueue dq(size);

    int choice, element;

    do {
        cout << "\n1. Enqueue at front";
        cout << "\n2. Dequeue from front";
        cout << "\n3. Enqueue at rear";
        cout << "\n4. Dequeue from rear";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue at front: ";
                cin >> element;
                dq.enqueueFront(element);
                break;

            case 2:
                dq.dequeueFront();
                break;

            case 3:
                cout << "Enter the element to enqueue at rear: ";
                cin >> element;
                dq.enqueueRear(element);
                break;

            case 4:
                dq.dequeueRear();
                break;

            case 5:
                dq.display();
                break;

            case 6:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 6);

    return 0;
}