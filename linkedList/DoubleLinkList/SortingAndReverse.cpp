#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *previous;
};

Node *list = NULL;    // Original doubly linked list
Node *reversedList = NULL; // New reversed copied list

// Insert in sorted order into doubly linked list
void insert(){
    Node *pointer = new Node();
    cout << "Enter value: ";
    cin >> pointer->data;
    pointer->next = NULL;
    pointer->previous = NULL;

    if (list == NULL) {
        list = pointer;
    }
    else if (pointer->data < list->data) {
        pointer->next = list;
        list->previous = pointer;
        list = pointer;
    }
    else {
        Node *current = list;
        while (current->next != NULL && current->next->data < pointer->data) {
            current = current->next;
        }
        pointer->next = current->next;
        if (current->next != NULL)
            current->next->previous = pointer;
        current->next = pointer;
        pointer->previous = current;
    }
}

// Copy the original list in reverse into a new doubly linked list
void copyAndReverseList(){
    // Move to the tail of the original list
    Node* tail = list;
    if (tail == NULL) {
        cout << "Original list is empty!" << endl;
        return;
    }

    while (tail->next != NULL)
        tail = tail->next;

    // Traverse from tail to head, adding at the end of new list
    while (tail != NULL) {
        Node* newNode = new Node();
        newNode->data = tail->data;
        newNode->next = NULL;
        newNode->previous = NULL;

        if (reversedList == NULL) {
            reversedList = newNode;
        }
        else {
            Node* temp = reversedList;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
            newNode->previous = temp;
        }

        tail = tail->previous;
    }

    cout << "Copied and reversed list created successfully!" << endl;
}

// Display a doubly linked list from head to tail
void display(Node* head){
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main(){
    int choice;
    while (true) {
        cout << "\n1. Insert\n2. Copy and Reverse\n3. Display Original\n4. Display Reversed Copy\n5. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            insert();
        else if (choice == 2)
            copyAndReverseList();
        else if (choice == 3)
            display(list);
        else if (choice == 4)
            display(reversedList);
        else if (choice == 5)
            break;
        else
            cout << "Invalid choice!" << endl;
    }
}
