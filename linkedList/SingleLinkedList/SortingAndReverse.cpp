#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *previous;
};
Node *list = NULL;
Node* head2 = NULL;


void insert(){
    Node *pointer=new Node();
    cin>>pointer->data;
    pointer->next=NULL;
    
    if (list == NULL || pointer->data < list->data) {
        // insert at head
        pointer->next = list;
        list = pointer;
    }
    else {
        Node *current = list;
        while (current->next != NULL && current->next->data < pointer->data) {
            current = current->next;
        }
        pointer->next = current->next;
        current->next = pointer;
    }
}
void copyAndReverseList(Node* head) {
    head2 = NULL; // clear any old data
    Node* current = head;
    while (current != NULL) {
        // Create a new node copying current node's data
        Node* newNode = new Node();
        newNode->data = current->data;

        // Insert new node at the head of new list to reverse
        newNode->next = head2;
        head2 = newNode;

        current = current->next;
    }
}

void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "How many numbers to insert? ";
    cin >> n;

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        insert();
    }

    cout << "\nOriginal sorted list: ";
    display(list);

    copyAndReverseList(list);

    cout << "Copied and reversed list: ";
    display(head2);

    return 0;
}