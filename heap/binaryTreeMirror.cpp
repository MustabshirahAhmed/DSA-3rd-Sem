// #include<iostream>
// using namespace std;

// //maxheap
// #include <iostream>
// #include<vector>
// using namespace std;

// struct tree{
//     int data;
//     tree* leftChild;
//     tree* rightChild;
//     tree* ysibling;
//     tree* osibling;
// };
// tree* head = NULL;
// tree* temp = NULL;

// void preOrder(tree* node){
//     if(node == NULL) return;

//     // Process current node
//     cout << node->data << " ";

//     // Recursively process left and right children
//     preOrder(node->leftChild);
//     preOrder(node->rightChild);
// }

// void print(vector<int> &heap){
//     for(int i=0; i<heap.size() ; i++){
//         cout<<heap[i]<<" ";
//     }
// }
// void mirror(tree* node){
//     if(node == NULL) return;

//     // Swap left and right children
//     tree* tempChild = node->leftChild;
//     node->leftChild = node->rightChild;
//     node->rightChild = tempChild;

//     // Recursively mirror left and right subtrees
//     mirror(node->leftChild);
//     mirror(node->rightChild);
// }
// void treemaking(vector<int> &heap) {
//     // If heap is empty, no tree to make
//     if(heap.size() == 0) {
//         head = NULL;
//         return;
//     }

//     // Create root node with first heap element
//     head = new tree();
//     head->data = heap[0];
//     head->leftChild = head->rightChild = head->osibling = head->ysibling = NULL;

//     // 'temp' keeps track of current parent node while attaching children
//     temp = head;

//     // A vector to keep track of nodes in the order they were created
//     // to easily access parents when adding new nodes.
//     vector<tree*> nodes;
//     nodes.push_back(head);

//     int currentParentIndex = 0;  // Index to track which parent we're adding children to

//     for(int i = 1; i < heap.size(); i++) {
//         // Create new node for each heap element
//         tree* newNode = new tree();
//         newNode->data = heap[i];
//         newNode->leftChild = newNode->rightChild = newNode->osibling = newNode->ysibling = NULL;

//         // Current parent we're adding children to
//         temp = nodes[currentParentIndex];

//         // Attach new node to the left if leftChild is empty
//         if(temp->leftChild == NULL) {
//             temp->leftChild = newNode;
//         }
//         // Else, attach to the right
//         else if(temp->rightChild == NULL) {
//             temp->rightChild = newNode;

//             // Set siblings between leftChild and rightChild
//             temp->leftChild->ysibling = temp->rightChild;
//             temp->leftChild->osibling = NULL;
//             temp->rightChild->osibling = temp->leftChild;
//             temp->rightChild->ysibling = NULL;

//             // Move to next parent when both left and right are occupied
//             currentParentIndex++;
//         }

//         // Add new node to our nodes vector for potential future parenting
//         nodes.push_back(newNode);
//     }
// }

// void insert(int value,vector<int> &heap){
//     heap.push_back(value);
//     int j=heap.size()-1;

//     while(!(j<=0)){
//         if(heap[(j-1)/2]<heap[j]){
//             int temp= heap[(j-1)/2];
//             heap[(j-1)/2]=heap[j];
//             heap[j]=temp;

//             j=(j-1)/2;
//         }
//         else{
//             break;
//         }
//     }
//     cout<<"HEAP: ";
//     print(heap);
//     cout<<endl;
//     treemaking(heap);
//     cout<<"Tree: ";
//     preOrder(head);
//     mirror(head);
//     cout<<endl;
//     cout<<"Mirror of tree: ";
//     preOrder(head);
//     cout<<endl;
// }


// int main(){
//     vector<int>heap;
//     int value;
//     int choice;
    
//     while(choice!=3){
//         cout<<"enter your choice:";
//         cin>>choice;

//         if (choice==1){
//             cout<<"Enter value to insert: ";
//             cin>>value;
//             insert(value,heap);
//         }
//         // if(choice==2){
//         //     DeleteHeap(heap);
//         // }
//         if(choice!=1 && choice!=2){
//             break;
//         }
//     }
    
// }
#include<iostream>
#include<vector>
using namespace std;

// Node structure for the binary tree
struct tree{
    int data;
    tree* leftChild;
    tree* rightChild;
    tree* ysibling;
    tree* osibling;
};

// Global pointers to maintain head (root of the tree) and temp (current insertion point)
tree* head = NULL;
tree* temp = NULL;

// Function to print the heap array
void print(vector<int> &heap){
    for(int i=0; i<heap.size(); i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

// Preorder traversal of binary tree (root, left, right)
void preOrder(tree* node){
    if(node == NULL) return;

    cout << node->data << " "; // visit root
    preOrder(node->leftChild); // left
    preOrder(node->rightChild); // right
}

// Function to mirror the binary tree
void mirror(tree* node){
    if(node == NULL) return;

    // Swap left and right child
    tree* tempChild = node->leftChild;
    node->leftChild = node->rightChild;
    node->rightChild = tempChild;

    // Recursively mirror left and right subtrees
    mirror(node->leftChild);
    mirror(node->rightChild);
}

// Function to build a binary tree from a heap represented as a vector
void treemaking(vector<int> &heap){
    if(heap.size() == 0) return;

    // Clear old tree if any
    head = new tree();
    head->data = heap[0];
    head->leftChild = head->rightChild = head->osibling = head->ysibling = NULL;

    // Level-order like construction using a queue (vector of pointers)
    vector<tree*> nodeQueue;
    nodeQueue.push_back(head);

    int index = 1; // start from second element in heap
    while(index < heap.size()){
        tree* parent = nodeQueue[0]; // front of the queue

        // Create new node for current heap element
        tree* newNode = new tree();
        newNode->data = heap[index];
        newNode->leftChild = newNode->rightChild = newNode->osibling = newNode->ysibling = NULL;

        // Attach new node as left or right child
        if(parent->leftChild == NULL){
            parent->leftChild = newNode;
        } 
        else if(parent->rightChild == NULL){
            parent->rightChild = newNode;
            // Manage sibling pointers
            parent->leftChild->ysibling = parent->rightChild;
            parent->rightChild->osibling = parent->leftChild;
            
            // Remove parent from queue once both children are filled
            nodeQueue.erase(nodeQueue.begin());
        }

        // Push new node to queue for further child insertions
        nodeQueue.push_back(newNode);
        index++;
    }
}

// Insert value in max-heap and rebuild tree and mirror it
void insert(int value, vector<int> &heap){
    heap.push_back(value); // add value at the end
    int j = heap.size() - 1;

    // Percolate up to maintain max-heap property
    while(j > 0 && heap[(j-1)/2] < heap[j]){
        swap(heap[(j-1)/2], heap[j]);
        j = (j-1)/2;
    }

    cout<<"HEAP: ";
    print(heap);

    // Build tree from updated heap
    treemaking(heap);

    cout<<"Tree (PreOrder): ";
    preOrder(head);
    cout<<endl;

    // Mirror the tree
    mirror(head);
    cout<<"Mirror of Tree (PreOrder): ";
    preOrder(head);
    cout<<endl;
}

int main(){
    vector<int> heap; // Heap stored as a vector
    int value;
    int choice = 0;
    
    while(choice != 3){
        cout<<"Enter your choice (1: Insert, 3: Exit): ";
        cin>>choice;

        if (choice == 1){
            cout<<"Enter value to insert: ";
            cin>>value;
            insert(value, heap);
        }
    }
}
