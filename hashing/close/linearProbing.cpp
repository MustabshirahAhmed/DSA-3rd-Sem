#include<iostream>
using namespace std;

void print(int *array, int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << endl;
    }
}

void insert(int Key, int size, int *array, bool *array2){
    int index = Key % size;
    if(array2[index] == false){
        array[index] = Key;
        array2[index] = true;
    }
    else{
        int i = 1;
        int index2;
        while(i <= size){
            index2 = index + i;
            if(array2)
            if(index2 >= size){
                index2 = index2 % size;
            }
            if(array2[index2] == false){
                array[index2] = Key;
                array2[index2] = true;
                break;
            }
            else{
                i++;
            }
        }
    }
    print(array, size);
}

void search(int size, int *array, int value){
    int i;
    for(i = 0; i < size; i++){
        if(array[i] == value){
            cout << "value found\n";
            return;
        }
    }
    cout << "value not found\n";
    return;
}

void Delete(int size, int *array, bool *array2, int value){
    int i;
    for(i = 0; i < size; i++){
        if(array[i] == value){
            array[i] = 0;
            array2[i] = false;
            cout << "value deleted\n";
            return;
        }
    }
    cout << "value not found to delete\n";
}

int main(){
    int size;
    int choice = -1;
    int value;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << endl;

    int array[size] = {0};
    bool array2[size] = {false};

    cout << "For insertion press 1 \nFor searching press 2 \nFor deletion press 3 \nFor exit press 0" << endl;

    while(choice != 0){
        cout << "enter your choice: ";
        cin >> choice;
        switch (choice){
            
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            insert(value, size, array, array2);
            break;

        case 2:
            cout << "Enter the value to search: ";
            cin >> value;
            search(size, array, value);
            break;

        case 3:
            cout << "Enter the value to delete: ";
            cin >> value;
            Delete(size, array, array2, value);
            break;

        default:
            if(choice != 0)
                cout << "invalid choice\n";
        }
    }
}
