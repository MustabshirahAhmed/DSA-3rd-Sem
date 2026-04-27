#include<iostream>
using namespace std;

struct BSN{
    int data;
    BSN *left;
    BSN *right;
};

BSN* insert(BSN *node, int value){

    if(node==NULL){
        BSN *temp= new BSN();
        temp->data=value;
        temp->left=NULL;
        temp->right=NULL;

        return temp;
    }
    if(value > node->data){
        node->right = insert(node->right, value);
    }
    else{
        node->left = insert(node->left, value);
    }
    return node;
}

void search(BSN *node, int value){
    if(node==NULL){
        cout<<"value not found";
        return;
    }
    if(value==node->data){
        cout<<"Value found: "<<node->data;
        return;
    }
    if(value>node->data){
        search(node->right,value);
    }
    else{
        search(node->left,value);
    }    
}

void preOrder(BSN *node){
    if(node!=NULL){
        cout<<node->data;
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(BSN *node){
    if(node!=NULL){
        inOrder(node->left);
        cout<<node->data;
        inOrder(node->right);
    }
}

void postOrder(BSN *node){
    if(node!=NULL){
        postOrder(node->left);
        postOrder(node->right);
        cout<<node->data;
    }
}

int main(){
    BSN *root=NULL;
    int value;
    int choice;
    cout<<"Please select the respective key to perform the required task:";
    cout<<"1. Insertion\n2.Searching\n3Pre-Order Traverse\n4.in-Order Traverse\n5.Post-Order Traverse\n";

    
    do{
        cin>>choice;
        switch (choice)
        {
        case 1:cout<<"Enter the value you want to insert: ";
                cin>>value;
                root=insert(root,value);
                break;
        case 2:cout<<"Enter the value to search: ";
                cin>>value;
                search(root,value);
            break;
        case 3:cout<<"Pre-OrderTraversing";
            preOrder(root);
            break;
        case 4:cout<<"In-Order Traversing";
            inOrder(root);
            break;
        case 5:cout<<"Post-Order Traversing";
            postOrder(root);
            break;
        default:

            break;
        }
    } while(choice!=0);
}