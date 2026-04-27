#include<iostream>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

struct adjVertices{
    void *adVertex;
    adjVertices* nextAdj;
};
struct vertex{
    stack<vertex*>myStack;
    public:int data;
    vertex* nextVertex;
    adjVertices* startAdj;
};
vertex* head = NULL;
// vertex* previous = NULL;

void insertVertex(vertex* &node, int name){
        
    vertex* newVertex = new vertex();
    // cout<<"Enter the Vertex number: ";
    newVertex->data = name;
    newVertex->nextVertex = NULL;
    newVertex->startAdj = NULL;
    
    if(node == NULL){
        node=newVertex;
    }
    else{
        vertex* temp= node;
        while(temp->nextVertex != NULL){
            temp = temp->nextVertex;
        }
        temp->nextVertex = newVertex;
    }
}
vertex* SearchVertex(int name) {
    vertex* current = head;
    // previous = NULL;

    while (current != NULL) {
        if (current->data == name) {
            return current;
        }
        current = current->nextVertex;
    }
    return NULL;
}

void insertEdge(){
    cout<<"Enter the starting vertex: ";
    int V1;
    cin>>V1;
    vertex* node = SearchVertex(V1);
    if(node == NULL){
        cout<<"Marham choro yr maham ki qasam edge na mila :(:(";
        return;
    }
    else{
        cout<<"Enter the number of Connected vertices: ";
        int edges;
        cin>>edges;

        for(int i=0 ; i<edges ; i++){
            cout<<"Enter "<<i+1<<" conection: ";
            int edge1;
            cin>>edge1;
            vertex* temp=SearchVertex(edge1);
            
            if(temp == NULL){
                cout<<"kundali Nahil mil rahi donon ki :( \n";
                return;
            }
            else{
                if(node->startAdj == NULL){
                    adjVertices* newNode = new adjVertices();
                    newNode->adVertex = temp;
                    node->startAdj = newNode;
                    adjVertices* newNode2 = new adjVertices();
                    newNode2->adVertex = node;
                    temp->startAdj = newNode2;
                    cout<<"Edging Hogyi Maleek aapki ;)\n";
                }
                else{
                    adjVertices* current = node->startAdj;
                    while(current->nextAdj != NULL){
                        current = current->nextAdj;
                    }
                    adjVertices* newNode = new adjVertices();
                    newNode->adVertex = temp;
                    current->nextAdj = newNode;

                    current = temp->startAdj;
                    while(current->nextAdj != NULL){
                        current = current->nextAdj;
                    }
                    adjVertices* newNode2 = new adjVertices();
                    newNode2->adVertex = node;
                    current->nextAdj = newNode2;
                    cout<<"Edging Hogyi Maleek aapki ;)\n";
                }

            }

        }
    }

}

void printGraphList(){
    vertex* temp = head;

    if(temp==NULL) return;

    while(temp != NULL){

        cout<<temp->data<<" : ";
        if(temp->startAdj != NULL){
            adjVertices* current = temp->startAdj;
            while(current != NULL){
                vertex *EdgeData = (vertex *)(current->adVertex);
                cout<< EdgeData->data <<" | ";
                current = current->nextAdj;
            }
        }
        cout<<endl;
        temp = temp->nextVertex;
    }
}


int main(){
int vertexName;
int i=0;
while(i<3){
    cout<<"enter vertex name: ";
    cin>>vertexName;
    insertVertex(head,vertexName);
    if(i>=1){
    insertEdge();
    }
    i++;
    printGraphList();
}
}