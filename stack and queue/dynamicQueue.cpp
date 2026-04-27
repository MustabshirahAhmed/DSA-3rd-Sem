#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Enqueued: " << value << endl;
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow!" << endl;
        return;
    }
    cout << "Dequeued: " << front->data << endl;
    Node* temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete temp;
}

void display() {
    if (front == NULL) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    Node* temp = front;
    cout << "Queue: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n=== Queue Menu ===\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 0:
            cout << "Exiting Queue program.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
