#include <iostream>
#include <malloc.h>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node *list = NULL;

void insert() {
    Node *pointer = (Node *)malloc(sizeof(Node));
    cin >> pointer->data;
    pointer->next = NULL;
    pointer->prev = NULL;

    if (list == NULL) {
        list = pointer;
        return;
    }

    Node *temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = pointer;
    pointer->prev = temp;
}

Node* search(int toSearch) {
    Node *current = list;
    while (current != NULL) {
        if (current->data == toSearch) {
            cout << "\nVALUE FOUND: " << current->data << "\n";
            return current;
        }
        current = current->next;
    }
    cout << "\nValue not found!!\n";
    return NULL;
}

void deleteNode(int value) {
    Node *toDelete = search(value);
    if (toDelete == NULL) {
        cout <<value <<" not found in the list!\n";
    }

    if (toDelete == list) {
        list = toDelete->next;
        if (list != NULL) {
            list->prev = NULL;
        }
    } else {
        toDelete->prev->next = toDelete->next;
    }

    if (toDelete->next != NULL) {
        toDelete->next->prev = toDelete->prev;
    }

    free(toDelete);
    cout<< value << " deleted from the list.\n";
}

void print() {
    Node *temp = list;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    for (int i = 0; i < 5; i++) {
        insert();
        print();
    }

    search(7);
    search(10);

    deleteNode(5);
    print();

    deleteNode(10);
    print();

    return 0;
}
