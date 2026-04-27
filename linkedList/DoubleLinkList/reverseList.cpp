#include<iostream>
using namespace std;

struct Node{
    Node *previous;
    Node *next;
    int data;
};

int bounds=0;
Node *head=NULL;

void print() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert(){
    Node *pointer = new Node();
    cin>>pointer->data;
    pointer->next = NULL;
    pointer->previous = NULL;

    if(head==NULL){
        head = pointer;
        bounds++;
        return;
    }

    Node *temporary = head;
    while(temporary->next != NULL){
        temporary = temporary->next;
    }
    temporary->next=pointer;
    pointer->previous=temporary;
    bounds++;
    return;
}

// void reverse(int times){

//     if (times <= 1 || head == NULL) 
//         return;

//     // for(int i=0 ; i<times ; i++){
//         int i=times-1;
//         int counter = 0;
//         Node *current = head;
        
//         while(counter<i){
//             // cout<<current->data;
//             current = current->next;
//             counter++;
//         }

//         for(int j=0 ; j<i ; j++){

//             Node *temp=current->previous;
//             Node *temp2 = current->next;

//             if (temp->previous)
//                 temp->previous->next = current;

//             else 
//                 head = current;
            
//             if (temp2)
//                 temp2->previous = temp;

//             // Swap pointers between A and B
//             current->previous = temp->previous;
//             temp->next = temp2;
//             temp->previous = current;
//             current->next = temp;

//             current = current->previous;

//             print();

//         }
//     // }

// }

void reverse(int times) {
    if (times <= 1 || head == NULL || times > bounds){
        cout<<"wrong input!! ";
        return;
    }


    Node* current = head;
    Node* temp = NULL;
    Node* nextNode = NULL;
    int count = 0;

    while (current != NULL && count < times) {
        // Swap next and previous
        nextNode = current->next;
        temp = current->previous;
        current->previous = current->next;
        current->next = temp;

        // Move to the next node (which was current->next before swap)
        current = nextNode;
        count++;
    }

    // Adjust head
    if (temp != NULL) {
        head = temp->previous;
    }

    // Connect last node of reversed part to remaining list
    if (head != NULL && current != NULL) {
        head->previous = NULL;
        Node* lastReversed = head;
        while (lastReversed->next != NULL)
            lastReversed = lastReversed->next;

        lastReversed->next = current;
        current->previous = lastReversed;
    }

    print();
}


int main(){
    int choice;
    do{
        cout<<"please enter your choice:\n1 : insert\n2 :reverse\n Press any key to terminate\n";
        cin>>choice;

        switch (choice)
        {
        case 1: insert();
            break;
        case 2: cout<<"please enter the number of nodes you want to reverse: ";
                int value;
                cin>>value;
                reverse(value);
        default:
            break;
        }
    }while(choice==1 || choice==2);
}