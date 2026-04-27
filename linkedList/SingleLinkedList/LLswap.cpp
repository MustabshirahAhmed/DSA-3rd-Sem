#include <iostream>
#include <malloc.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* list = NULL;

void insert(int value) {
    Node* pointer = (Node*)malloc(sizeof(Node));
    pointer->data = value;
    pointer->next = NULL;
    if (list == NULL) {
        list = pointer;
        return;
    }
    Node* temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = pointer;
}

void swapNodes(int value1, int value2) {
    if (value1 == value2) return;

    Node *prev1 = NULL, *swap1 = list;
    while (swap1 && swap1->data != value1) {
        prev1 = swap1;
        swap1 = swap1->next;
    }

    Node *prev2 = NULL, *swap2 = list;
    while (swap2 && swap2->data != value2) {
        prev2 = swap2;
        swap2 = swap2->next;
    }

    if (!swap1 || !swap2) {
        cout << "Values not found in the list" << endl;
        return;
    }

    if (prev1) prev1->next = swap2;
    else list = swap2;

    if (prev2) prev2->next = swap1;
    else list = swap1;

    Node* temp = swap2->next;
    swap2->next = swap1->next;
    swap1->next = temp;
}

void print() {
    Node* temp = list;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int value1, value2;
    for (int i = 0; i < 5; i++) {
        int value;
        cin >> value;
        insert(value);
    }
    print();
    cout << "Enter two nodes to swap: ";
    cin >> value1 >> value2;
    swapNodes(value1, value2);
    print();
}
