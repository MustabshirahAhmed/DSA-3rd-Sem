#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

struct tree{
    float data;
    tree* leftChild;
    tree* rightChild;
    tree* ysibling;
    tree* osibling;
};

int level;
tree* head = NULL;
bool found = false;
vector<float> heap;

void getPredecessors(int index){
    cout << fixed << setprecision(2);
    // if(index == 0){
    //     cout<<"No predecessors of "<<heap[index]<<endl;
    //     return;
    // }
    cout<<"Predecessors of "<< heap[index]<<": ";
    while(index > 0){
        index = (index - 1) / 2;
        cout<<heap[index]<<" ";
    }
    cout<<endl;
    cout<<"Successors: ";
}

void getlevel(int index){
    level = 0;
    int leftchildren = 0;
    for(int i = index; i < heap.size(); ){
        i = (2*i)+1;
        leftchildren++;
    }
    int rightchildren = 0;
    for(int i = index; i < heap.size(); ){
        i = (2*i)+1;
        rightchildren++;
    }

    level = (leftchildren-rightchildren);
}

void searchHeap(float value){
    for(int i = 0; i <heap.size(); i++){
        if(heap[i] == value){
            getPredecessors(i);
            getlevel(i);
            break;
        }
    }
}

void getSuccessors(tree* node){
    if(node == NULL) return;
    cout << fixed << setprecision(2);

    if(found){
        searchHeap(node->data);
        found = false;
    }

    // if(node->leftChild == NULL && node->rightChild == NULL){
    //     cout << "\nNo successors for " << node->data << endl;
    //     return;
    // }

    if(node->leftChild){
        cout << node->leftChild->data << " ";
    }
    if(node->rightChild){
        cout << node->rightChild->data << " ";
    }     
    cout << endl;

    getSuccessors(node->leftChild);
    getSuccessors(node->rightChild);
}

void search(tree *node, float value){
    if(node == NULL) return;

    cout << fixed << setprecision(2);

    if(value == node->data){
        cout<<"Value found: "<<node->data<<endl;
        found = true;
        getSuccessors(node);
        return;
    }

    search(node->leftChild, value);
    search(node->rightChild, value);
}

void treemaking(vector<float> &heap){
    if(heap.size() == 0) return;

    head = new tree();
    head->data = heap[0];
    head->leftChild = head->rightChild = head->osibling = head->ysibling = NULL;

    vector<tree*> nodeQueue;
    nodeQueue.push_back(head);

    int index = 1;
    while(index < heap.size()){
        tree* parent = nodeQueue[0];

        tree* newNode = new tree();
        newNode->data = heap[index];
        newNode->leftChild = NULL; 
        newNode->rightChild = NULL;
        newNode->osibling = NULL;
        newNode->ysibling = NULL;

        if(parent->leftChild == NULL){
            parent->leftChild = newNode;
        } 
        else if(parent->rightChild == NULL){
            parent->rightChild = newNode;
            parent->leftChild->ysibling = parent->rightChild;
            parent->rightChild->osibling = parent->leftChild;
            nodeQueue.erase(nodeQueue.begin());
        }

        nodeQueue.push_back(newNode);
        index++;
    }
}

void insert(float value, vector<float> &heap){
    heap.push_back(value);
    int j = heap.size() - 1;

    while(j > 0 && heap[(j-1)/2] < heap[j]){
        swap(heap[(j-1)/2], heap[j]);
        j = (j-1)/2;
    }

    treemaking(heap);
}

int main(){
    cout << fixed << setprecision(2); //tpprint points of float

    float value;
    int choice = 0;

    while(choice > -1 && choice < 5){
        cout<<"\nEnter your choice (1: Insert,\n 2: Search,\n 3: TotalNodes, \n4: Level): ";
        cin>>choice;

        if (choice == 1){
            cout<<"Enter value to insert: ";
            cin>>value;
            insert(value, heap);
        }
        else if (choice == 2){
            cout<<"Enter value to search: ";
            cin>>value;
            search(head, value);
        }
        else if(choice == 3){
            cout<<"Total number of nodes: "<< heap.size();
        }
        else if(choice == 4){
            cout<< "Level: "<<level;
        }
    }    
}
