#include<iostream>
using namespace std;

int main(){
    int num1,num2;
    cin>>num1>>num2;

    int arr[num1];

    for(int i =0; i<num1; i++){//입력
        cin>>arr[i];
        if(arr[i] < num2){cout<<arr[i]<<" ";}
    }
}