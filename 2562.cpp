#include<iostream>
using namespace std;

int main(){
    int arr[9];
    int max=1,cnt=0;

    for(int i=0; i<9; i++){
        cin>>arr[i];
        if(arr[i] > max){
            max = arr[i];
            cnt = i;
        }
    }
    cout<<max<<"\n"<<cnt+1;

}