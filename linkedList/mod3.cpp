#include <iostream>
#include <malloc.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *list = NULL; // Head of the linked list

// Utility: Create a new node with given value
Node* createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insert() {
    int value;
    cin >> value;
    int modValue = value % 3;
    
    // Create one node to eventually append at the end.
    Node *finalNode = createNode(value);

    // If the list is empty, simply set it to the final node.
    if (list == NULL) {
        list = finalNode;
        return;
    }
    
    // Traverse the list and insert duplicates after every matching node.
    Node *temp = list;
    while (temp != NULL) {
        if (temp->data % 3 == modValue) {
            // Create a duplicate node.
            Node *dup = createNode(value);
            dup->next = temp->next;
            temp->next = dup;
            // Advance temp to the node after the duplicate to avoid infinite loop.
            temp = dup->next;
        } else {
            temp = temp->next;
        }
    }
    
    // Append the final node at the end.
    temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = finalNode;
}

void print() {
    Node *current = list;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // For testing, expecting 6 inputs.
    for (int i = 0; i < 6; i++) {
        insert();
        print(); // Print after every insertion
    }
    return 0;
}
