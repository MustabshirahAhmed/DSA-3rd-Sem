#include<iostream>
using namespace std;
int main(){
    int array[5]={87,54,32,12,34};
    int i;
    
    int newTemp;
    for(i=0; i<4;i++){
        int min=i;
        for(int j=i+1; j<5; j++){
            if(array[j]<array[min]){
                min=j;
            }
        }
        int temp = array[i];
        array[i]=array[min];
        array[min] = temp;
    }
    for(int j=0;j<5;j++){
        cout<<array[j]<<" ";
    }
}