#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node *list = NULL;
Node *last = NULL;         // Pointer to last node
int countNodes = 0;        // Node count

void print() {
    Node *temp = list;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insert() {
    Node *pointer = new Node();
    cin >> pointer->data;
    pointer->next = NULL;
    pointer->prev = NULL;

    if (list == NULL) {
        list = pointer;
        last = pointer;
        countNodes++;
        return;
    }

    Node *temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = pointer;
    pointer->prev = temp;
    last = pointer;
    countNodes++;
}
void swap(Node *a, Node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
Node* partition(Node *low, Node *high) {
    int pivot = high->data;      // Set pivot as last node's data
    Node *i = low->prev;

    for (Node *j = low; j != high; j = j->next) {
        if (j->data <= pivot) {
            if (i == NULL)
                i = low;
            else
                i = i->next;
            swap(i, j);
        }
    }

    if (i == NULL)
        i = low;
    else
        i = i->next;

    swap(i, high);
    return i;
}

// Quick Sort recursive function
void quickSort(Node *low, Node *high) {
    if (high != NULL && low != high && low != high->next) {
        Node *p = partition(low, high);
        quickSort(low, p->prev);
        quickSort(p->next, high);
    }
}


int main(){
    for (int i = 0; i < 5; i++) {
        insert();
    }
    cout << "\nNumber of nodes: " << countNodes << endl;
    cout << "Before sorting: ";
    print();

    quickSort(list, last);

    cout << "After Quick Sort: ";
    print();

    return 0;
}