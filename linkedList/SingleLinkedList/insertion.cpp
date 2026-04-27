#include<iostream>
#include<malloc.h>
using namespace std;


struct Node{
    int data;
    Node *next;
};
Node *list = NULL;
Node *previous=NULL;

void insert(){
    Node *pointer=(Node*)(malloc(sizeof(Node)));
    cin>>pointer->data;
    pointer->next=NULL;
    
    if(list==NULL){
        list=pointer;
    }
    else{
        Node *current=list;
        while(current->next !=NULL){
            current=current->next;
        }
        current->next=pointer;
    }
}
void print(){
    Node *current=list; 
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
}

Node* search(int toSearch){
    Node *current=list;
    while(current != NULL){
        if(current->data == toSearch){
            cout<<"\nVALUE FOUND: ";
            cout<< current->data<<"\n";

            return current;
        }
        else{
            previous=current;
            current=current->next;
        }
    }
    cout<<"\nValue not found!! ";
}

void ToDelete(int toDel){
    Node* current=search(toDel);
    if(current==list){
        Node *temp=list;
        list=list->next;
        free(temp);
    }
    else{
        previous->next=current->next;
        free(current);
    }
}
int main(){
    for(int i=0;i<4;i++){
        insert();
        print();
    }
    // search(23);
    ToDelete(12);
    print();
}