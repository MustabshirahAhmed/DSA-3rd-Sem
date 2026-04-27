#include<iostream>
using namespace std;
int arr[8] = {1,5,4635,3634,473,38,5,456};
int toSearch;
int main(){
    cout<<"enter toSearch value";
    cin>>toSearch;
    for(int i=0;i<8;i++){
        if(arr[i] == toSearch ){
            cout<<toSearch<<"found at "<<i<<" ";
        }
    }
}