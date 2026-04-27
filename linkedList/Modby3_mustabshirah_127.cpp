#include<iostream>
#include<malloc.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node *list=NULL;

void insert(){
    Node *pointer=(Node*)(malloc(sizeof(Node)));
    cin>>pointer->data;
    int modValue=pointer->data%3;
    int counter=1;
    pointer->next=NULL;

    if(list==NULL){
        list=pointer;
        
    }
    else{
        Node *temp=list;
        while(temp->next!=NULL){
            if(counter==modValue){
                Node *current=pointer;
                current->next=NULL;
                current->next=temp->next;
                temp->next=current;
                counter=1;
                temp=current->next;
            }
            else{
                counter++;
                temp=temp->next;
            }
        }
        temp->next=pointer;
    }
}
void print(){
    Node *current=list; 
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
}
int main(){
    for (int i=0;i<6;i++){
        insert();
        print();
    }
}
