//maxheap
#include <iostream>
#include<vector>
using namespace std;

void print(vector<int> &heap){
    for(int i=0; i<heap.size() ; i++){
        cout<<heap[i]<<" \n";
    }
}
void insert(int value,vector<int> &heap){
    heap.push_back(value);
    int j=heap.size()-1;

    while(!(j<=0)){
        if(heap[(j-1)/2]<heap[j]){
            int temp= heap[(j-1)/2];
            heap[(j-1)/2]=heap[j];
            heap[j]=temp;

            j=(j-1)/2;
        }
        else{
            break;
        }
    }
    print(heap);
    
}

void DeleteHeap(vector<int>&heap){
    int j=heap.size()-1;
    int temp=heap[0];
    heap[0]=heap[j];
    heap[j]=temp;
    heap.pop_back();

    int i=0;
    
    while((2*i)+1 < heap.size()){

        int largest = i;
        int leftchild = (2*i)+1;
        int rightchild = (2*i)+2;

        if(leftchild < heap.size() && heap[leftchild] > heap[largest])
        largest = leftchild;
    
        if(rightchild < heap.size() && heap[rightchild] > heap[largest])
        largest = rightchild;
    
        if(largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        } 
        
        else {
            break;
        }
    }
    print(heap);
}

int main(){
    vector<int>heap;
    int value;
    int choice;
    
    while(choice!=3){
        cout<<"enter your choice:";
        cin>>choice;

        if (choice==1){
            cout<<"Enter value to insert: ";
            cin>>value;
            insert(value,heap);
        }
        if(choice==2){
            DeleteHeap(heap);
        }
        if(choice!=1 && choice!=2){
            break;
        }
    }
    
}