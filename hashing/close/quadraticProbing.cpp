
//delete function not made yetttttttttttt

#include<iostream>
using namespace std;
void print(int *array,int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<endl;
    }
}
void insert(int Key,int size, int *array, bool *array2 ){
    int index = Key%size;
    if(array2[index]==false){
        array[index]=Key;
        array2[index]=true;
    }
    else{
        int i=1;
        int index2;
        while(i<=size){
            index2=(index+(i*i));
            if(index2 >= size){
                index2 = index2%size;
            }
            if(array2[index2]==false){
                array[index2]=Key;
                array2[index2]=true;
                break;
            }
            else{
                i++;
            }
        }
    }
    print(array,size);

}
void search(int size, int *array,int value,bool *array2){
    int index = value % size;
    int i = 0;
    while (i < size) {
        int index2 = (index + (i * i)) % size;
        if (array2[index2] == true && array[index2] == value) {
            cout << "Value  found " << endl;
            return;
        } 
        else if (array2[index2] == false) {
            cout << "Value not found." << endl;
            return;
        }
        i++;
    }
    cout << "Value " << value << " not found." << endl;

}
void Delete(int size, int *array, bool *array2, int value){
    int index = value % size;
    int i = 0;
    while (i < size) {
        int index2 = (index + (i * i)) % size;

        if (array2[index2] == true && array[index2] == value) {
            array2[index2] = false;
            array[index2] = 0; // or -1 to mark deleted if needed
            cout << "Value deleted" << endl;
            return;
        } 
        else if (array2[index2] == false) {
            cout << "Value not found to delete." << endl;
            return;
        }
        i++;
    }
    cout << "Value not found." << endl;
}

int main(){
    int size;
    int choice = -1;
    int value;
    cout<<"Enter the size of the array: ";
    cin>>size;
    cout<<endl;
    int array[size]={0};
    bool array2[size]={false};

    cout<<"For insertion, press1\nFor searching press 2\nFor deletion press 3\nFor exit press any key\n";
    while(choice!=0){
        cout<<"enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:cout<<"Enter the value to insert: ";
               cin>>value;
               insert(value,size,array,array2);
            break;
        case 2: cout<<"Enter the value to search: ";
                cin>>value;   
                search(size, array,value,array2);
            break;
        case 3: cout<<"Enter the value to delete: ";
                cin>>value;
                Delete(size,array,array2,value);
            break;
        default:
            return 0;
            }
    }
}