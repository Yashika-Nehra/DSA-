#include <iostream>
using namespace std;

class PriorityQueue {
    int capacity;
    int count;
    int *arr;

public:
    PriorityQueue(int s) {
        capacity = s;
        count = 0;
        arr = new int[capacity];
    }

    ~PriorityQueue() {
        delete[] arr;
    }

    void enqueue(int x) {
        if (count == capacity) {
            cout << "Overflow" << endl;
            return;
        }

        int i;
        for (i = count - 1; (i >= 0 && arr[i] > x); i--) {
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = x;
        count++;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Underflow" << endl;
            return;
        }
        for (int i = 0; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;

    cout << "Enter the size of the priority queue: ";
    cin >> size;

    PriorityQueue pq(size);

    int choice, element;

    do {
        cout << "1. Enqueue 2. Dequeue 3. Display 4. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> element;
                pq.enqueue(element);
                break;
            case 2:
                pq.dequeue();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}