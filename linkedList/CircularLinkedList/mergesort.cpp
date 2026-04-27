#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insert() {
    Node *p = new Node;
    cin >> p->data;
    if (!head) {
        p->next = p;
        head = p;
    } else {
        Node *t = head;
        while (t->next != head) t = t->next;
        t->next = p;
        p->next = head;
    }
}

void print() {
    if (!head) return;
    Node *t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << endl;
}

void breakCircle() {
    if (!head) return;
    Node *t = head;
    while (t->next != head) t = t->next;
    t->next = NULL;
}

void makeCircular() {
    if (!head) return;
    Node *t = head;
    while (t->next) t = t->next;
    t->next = head;
}

Node* merge(Node *a, Node *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

void split(Node *source, Node* &a, Node* &b) {
    Node *slow = source, *fast = source->next;
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    a = source;
    b = slow->next;
    slow->next = NULL;
}

void mergeSort(Node* &h) {
    if (!h || !h->next) return;
    Node *a, *b;
    split(h, a, b);
    mergeSort(a);
    mergeSort(b);
    h = merge(a, b);
}

int main() {
    int n;
    cout << "How many? ";
    cin >> n;
    for (int i = 0; i < n; i++) insert();
    cout << "Before: "; print();
    breakCircle();
    mergeSort(head);
    makeCircular();
    cout << "After: "; print();
    return 0;
}
