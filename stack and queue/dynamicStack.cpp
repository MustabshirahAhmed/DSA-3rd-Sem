#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << "Pushed: " << value << endl;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow!" << endl;
        return;
    }
    cout << "Popped: " << top->data << endl;
    Node* temp = top;
    top = top->next;
    delete temp;
}

void display() {
    if (top == NULL) {
        cout << "Stack is Empty!" << endl;
        return;
    }
    Node* temp = top;
    cout << "Stack: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n=== Stack Menu ===\n";
        cout << "1. Push\n2. Pop\n3. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 0:
            cout << "Exiting Stack program.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
