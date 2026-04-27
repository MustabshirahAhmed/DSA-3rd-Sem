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
    
    if(list==NULL){
        list=pointer;
    }
    else{
        Node *current=list;
        while(current->next != list){
            current=current->next;
        }
        current->next=pointer;
    }
    previous=pointer;
    pointer->next=list;
}
void print(){
    Node *current=list; 
    do{
        cout<<current->data<<" ";
        current=current->next;
    }while(current!=list);
}
Node* search(int toSearch){
    Node *current=list;
    do{
        if(current->data == toSearch){
            cout<<"VALUE FOUND";
            cout<<": " <<current->data<<"\n";
            return current;
        }
        else{
            previous=current;
            current=current->next;
        }
    }    while(current != list);
    cout<<"Value not found!! ";
    return NULL;
}

void ToDelete(int toDel){
Node *current=search(toDel);
if(current==list){
        Node *temp=list;
        list=list->next;
        free(temp);
        previous->next=list;
    }
    else{
        previous->next=current->next;
        free(current);
    }
}
int main(){
    for(int i=0;i<5;i++){
        insert();
        print();
    }
    ToDelete(56);
    print();
}