#include<iostream>
using namespace std;
int main(){
    int array[10]={23,23,34,45,56,56,56,67,78,98};
    int left=0;
    int right=10;
    int midpoint;
    int tosearch;
    cout<<"please enter number to search: ";
    cin>>tosearch;
    // while(left<=right){

    //     midpoint=(left+right)/2;
    //     if(midpoint==tosearch){
    //         cout<<tosearch<<" found at index "<<midpoint<<endl;
    //     }
    //     else if(tosearch>midpoint){
    //         left=midpoint+1;
    //     }
    //     else{
    //         right=midpoint-1;
    //     }
    // }
    while(left<=right){

        midpoint=(left+right)/2;
        if(array[midpoint]==tosearch){
            cout<<tosearch<<" found "<<endl;
            break;
        }
        else if(tosearch>array[midpoint]){
            left=midpoint+1;
        }
        else{
            right=midpoint-1;
        }
    }
    if(left>right){
        cout<<"value not found :(";
    }
    else{
    while(array[midpoint]==array[midpoint-1]){
        if((midpoint-1)<0)
        break;
        else{
            cout<<midpoint-1<<" ";
            midpoint=midpoint-1;
        }
    }
    
    while(array[midpoint]==array[midpoint+1]){
        cout<<midpoint+1<<" ";
        midpoint=midpoint+1;
    }
    }
    
}
